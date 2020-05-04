#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void f() {
	while (true) {
		cout << "yo"  << flush;
		usleep(10000);
	}
}

void g() {
	while (true) {
		cout << "ho"  << flush;
		usleep(20000);
	}
}


int main() {
	thread t1( f );
	thread t2( g );

	t1.join();
	t2.join();
}
