#include <iostream>
#include <thread>
#include <unistd.h>
#include <cmath>

using namespace std;

uint32_t count1;
uint32_t count2;

void countPrimes(uint32_t* primeCount, uint32_t a, uint32_t b) {
	uint32_t count = 0;
	if (a == 2)
		count = 1;
	// write your prime number count code here...
	for (uint32_t i = a|1; i <= b; i += 2) {
		for (uint32_t j = 3; j <= sqrt(i); j += 2)
			if (i % j == 0)
        goto notPrime;
    count++;
	notPrime: ;
	}
	(*primeCount) = count;
}



int main() {
	// benchmark how long countPrimes takes for a single thread
	const uint32_t n = 8000000;
#if 0
	// single threaded
	countPrimes(&count1, 2,  n);
  cout << count1 << '\n';
#endif
	
	//	#if 0
	count1 = 0;
	count2 = 0;
	
	// now benchmark with 2 threads
	thread t1( countPrimes, &count1, 1,  n/2);
	thread t2( countPrimes, &count2, n/2+1, n );

	t1.join();
	t2.join();
	cout << count1 + count2 << '\n';
	//#endif
}
