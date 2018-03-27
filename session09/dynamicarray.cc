#include <iostream>
using namespace std;

int main() {
	const int n = 1000000000;
	bool* primes = new bool[n];
	primes[0] = primes[1] = false;
	for (uint64_t i=2; i < n; ++i)
		primes[i] = true;

	// 2 3 x 5 x 7 x x x  11 x  13 x  x   x 17  x 19 20 21 22 23 ....
	for (uint64_t i = 2 * 2; i < n; i += 2)
		primes[i] = false;
	for (uint64_t i = 3; i < n; ++i)
		if (primes[i]) {
			// i=97
			for (uint64_t j = i*i; j < n; j += 2*i)
				primes[j] = false;
		}
	

	delete[] primes;

}
