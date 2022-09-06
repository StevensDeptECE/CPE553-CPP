#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono_literals;

condition_variable cv;
mutex cv_m;
atomic<int> i{0};
 
void waits(int idx) {
	unique_lock<mutex> lk(cv_m);
	auto now = chrono::system_clock::now();
	if(cv.wait_until(lk, now + idx*100ms, [](){return i == 1;}))
		cerr << "Thread " << idx << " finished waiting. i == " << i << '\n';
	else
		cerr << "Thread " << idx << " timed out. i == " << i << '\n';
}
 
void signals() {
	this_thread::sleep_for(120ms);
  cerr << "Notifying...\n";
	cv.notify_all();
	this_thread::sleep_for(100ms);
	i = 1;
	cerr << "Notifying again...\n";
	cv.notify_all();
}
 
int main() {
	thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
	t1.join(); 
	t2.join();
	t3.join();
	t4.join();
}
