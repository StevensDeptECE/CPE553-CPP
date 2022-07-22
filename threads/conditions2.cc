	#include <fcntl.h>
	#include <unistd.h>
	#include <condition_variable>
	#include <iostream>
	#include <thread>
	using namespace std;
	using namespace std::chrono_literals;

	constexpr uint32_t blockSize = 32768;
	char* buf1;
	char* buf2;
	char* processbuf = buf1;
	char* readbuf = buf2;

	mutex readMutex;
	mutex procMutex;
	//condition_variable readCV;
	//condition_variable procCV;
	int fh;
	int bytesRead;


	void nextRead() {
		while (true) {
			{
  	  	unique_lock<mutex> readLock(readMutex);
				bytesRead = read(fh, readbuf, blockSize);
				for (int i = 0; i < 5; i++) {
					cerr << "reading..." << endl;
					usleep(100000);
					readLock.unlock();
				}
				cerr << "notifying..." << endl;
			}
			if (bytesRead != blockSize)  // last time, end here!
				return;
			unique_lock<mutex> procLock(procMutex); // wait for process to complete
		}
	}

	void process(char* buf, uint32_t bytesRead) {
		cout << "processing..." << endl;
 		usleep(100000);
  }

	int thready() {
		buf1 = new char[blockSize];
		buf2 = new char[blockSize];
		fh = open("bigfile.dat", O_RDONLY);
		if (fh < 0) {
			throw std::runtime_error("cannot open file!");
		}
		int currentBytesRead = read(fh, buf1, blockSize);
		thread reader(nextRead);
		process(processbuf, currentBytesRead);
		while (true) {
			{
  		  unique_lock<mutex> readLock(readMutex);
			  cout << "back from wait" << endl;
			  swap(processbuf, readbuf);  // switch to other buffer for next time
			  currentBytesRead = bytesRead;  // create local copy
				// TODO: is the above a problem? what if
			}
 		  unique_lock<mutex> procLock(procMutex);
			process(processbuf, currentBytesRead);
		}
		reader.join();

		delete[] buf1;
		delete[] buf2;
	}


	int main() {
		try {
			thready();
		}catch(std::exception& e) {
			cerr << e.what() << '\n';
		}
		return 0;
	}