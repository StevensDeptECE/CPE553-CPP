#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void f() {
	for (;;) {
		cout << "hello" << flush;
		 sleep(1);
	}
}

void g() {
	for (;;){
     cout << "bye" << flush;
		 sleep(2);
	}
}

int main() {
	thread t1(f);
	thread t2(g);
	t1.join();
	t2.join();
}
