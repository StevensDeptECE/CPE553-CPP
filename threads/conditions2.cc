#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono_literals;

constexpr uint32_t blockSize = 32768;
char* buf1;
char* buf2;
char* processbuf = buf1;
char* readbuf = buf2;

mutex m;
condition_variable cv;
int fh;
int bytesRead;

void nextRead(char* buf) {
	unique_lock<mutex> lk(m);
	bytesRead = read(fh, readbuf, blockSize);
	lk.unlock();
	cv.notify_one();
}

void process(char* buf) {
}

void setup() {
	buf1 = new char[blockSize];
	buf2 = new char[blockSize];
	fh = open("bigfile.dat", O_RDONLY);
	int currentBytesRead = read(fh, buf1, blockSize);
	thread reader(nextRead);
	process(processbuf, currentBytesRead);
	while (cv.wait(lk, []{return true;})) {
		cout << "back from wait" << endl;
		swap(processbuf, readbuf); // switch to other buffer for next time
		currentBytesRead = bytesRead; // copy locally so thread can do the other one
		//TODO: is the above a problem? what if
		process(processbuf, currentBytesRead);
	}
  reader.join();
	
	delete [] buf1;
	delete [] buf2;
}

uint32_t waits(condition_variable& cv, char* buf, uint32_t bytesRead) {
	unique_lock<mutex> lk(cv_m);
	cv.wait(lk, []{      });	
}
 
void readBlock(condition_variable& cv,
							 int fh, uint32_t blockSize, char* buf) {
	int bytesRead = read(fh, buf, blockSize);
	if (bytesRead > 0) {
		::bytesRead = bytesRead;
		cv.notify_all();
	}
}
 
int main() {
	thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
	t1.join(); 
	t2.join();
	t3.join();
	t4.join();
}
