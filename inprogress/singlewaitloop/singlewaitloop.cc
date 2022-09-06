#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

// header files for sockets
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

class Ex {
public:
	const char* filename;   // the filename in which the error occurred
	const uint32_t lineNum; // the linenumber of the file
	const char* msg;       // a string message, if any (nullptr if not)
public:
	Ex(const char filename[], uint32_t lineNum, const char msg[])
    : filename(filename), lineNum(lineNum), msg(msg) {}
	friend std::ostream& operator <<(std::ostream& s, const Ex& e) {
		return s << e.filename << ": " << e.lineNum <<  '\t' << e.msg << '\n';
	}
};


mutex m;
condition_variable cv;
bool ready = true;

void mainWorkLoop() {
  unique_lock<std::mutex> lk(m);
  while (true) {
    cv.wait(lk, []{return ready;});
    cout << "executing main loop\n";
    ready = false;
    sleep(1);
  }
}

#define testResult(result, msg)      \
	if ((result) < 0) {                \
  throw Ex(__FILE__, __LINE__, msg);\
	}

struct sockaddr_in sockaddress;
struct sockaddr_in client_addrconfig;
socklen_t client_length = sizeof(client_addrconfig);
int sckt;
int16_t port = 8003;

void initializeSocket() {
  int yes = 1;
  testResult(sckt = socket(AF_INET, SOCK_STREAM, 0), "SOCKET");
  testResult(setsockopt(sckt, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)), "SETSOCKOPT");

  bzero((char*) &sockaddress, sizeof(sockaddress));
  sockaddress.sin_family = AF_INET;
  sockaddress.sin_addr.s_addr = INADDR_ANY;
  sockaddress.sin_port = htons(port);
  ::bind(sckt, (struct sockaddr *)& sockaddress, sizeof(sockaddress));
  testResult(listen(sckt, 20), "LISTEN");
}


void waitForSocket() {

	while (true) {
		cout << "WAITING CONNECTION." << endl;
    	int returnsckt = accept(sckt, (struct sockaddr *) &client_addrconfig, &client_length);
    	if (returnsckt >= 0) {
    		cout << "CONNECT SUCCESSFULLY" << "\n";
        ready = true;
        cv.notify_one();
    		close(returnsckt);
   	 	} else {
    		throw Ex(__FILE__, __LINE__, "CONNECTION_FAILURE");
    	}
  }
}

void waitForEvent() {
  while(true) {
    char c;
    cin >> c; // wait for key press
    ready = true;
    cv.notify_one();    
  }
}


int main() {
  try {
    initializeSocket();
    thread socketThread(waitForSocket);
    thread eventThread(waitForEvent);
    mainWorkLoop();
  } catch(const Ex& e) {
    cout << e << '\n';
  } catch(...) {
    cout << "unmatched exception?\n";
  }
}
