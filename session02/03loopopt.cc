#include <iostream>
#include <unistd.h>
using namespace std;
/*
	If your code runs different with optimization and without, there are only two possibilities

	1. There is a bug in the compiler
	2. Your program is wrong.

	Guess which is more likely

*/

//sum (1 .. n) = n(n+1) / 2   b(b+1)/2 - a(a+1)/2
uint64_t sum(uint64_t a, uint64_t b) {
	uint64_t s = 0;
	for (uint64_t i = a; i <= b; i+=3)
		s += i;
	return s;
}

uint64_t sum2(uint64_t a, uint64_t b) {
	uint64_t s = 0;
	for (uint64_t i = a; i <= b; i++)
		s += i*i;
	return s;
}

double sum3(uint64_t a, uint64_t b) {
	double s = 0;
	for (uint64_t i = a; i <= b; i++)
		s += 1.0/i;
	return s;
}


int main() {
	for (uint64_t i = 0; i < 1000000000LL; i++)
		;
	//usleep(10); // to delay, use usleep (microseconds) or sleep (seconds)
	//sleep(1);
//		cout << sum(100000, 3000000000) << '\n';
		cout << sum3(100000, 500000000) << '\n';
}
