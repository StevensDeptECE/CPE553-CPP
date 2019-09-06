#include <iostream>
#include <unistd.h>
using namespace std;

//sum (1 .. n) = n(n+1) / 2   b(b+1)/2 - a(a+1)/2
uint64_t sum(uint64_t a, uint64_t b) {
	uint64_t s = 0;
	for (uint64_t i = a; i <= b; i++)
		s += i;
	return s;
}

uint64_t sum2(uint64_t a, uint64_t b) {
	uint64_t s = 0;
	for (uint64_t i = a; i <= b; i++)
		s += i*i;
	return s;
}


int main() {
	for (int i = 0; i < 1000000000; i++)
		;
	usleep(10); // to delay, use usleep (microseconds) or sleep (seconds)
	sleep(1);
	//	cout << sum(100000, 3000000000) << '\n';
	//	cout << sum(100000, 300000000) << '\n';
}
