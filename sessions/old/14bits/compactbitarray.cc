#include <iostream>
#include <cmath>
using namespace std;

int main() {
#if 0
	//	bool isPrime[1000000000]; // 00000000
	int a = 0xAC0135; // 1010 1100 0000 0001 0x11 0101

	a = a | (1 << 6); // set bit 6 to 1
	//a = a | (0x8000000000000000LL >> 58;


	//  01010101010001111y000011101010
	//  000000000000000001000000000000
	//  111111111111111110111111111111
	a = a & ~(1 << 12); // clear bit y

	// test if bit is true

	//  010101010100011110000z1101010
	if (a & (1 << 7)) { // test if bit z is true
		// do something
	}

	//  010101010100011110000z1101010
	a = a ^ (1 << 7); // toggle bit z (flip)
	int j = 11; // 1011
	j = j ^ 5; //  0101
	//             1110
	j = j ^ 5; //  0101
	//             1011
#endif
	
	const int n = 1000000000;
	const int WORDS = (n + 63) / 64;
	uint64_t* isPrime = new uint64_t[WORDS];
#if 0
	for (int i = 2; i < n; i++) {
		int element = i / 64; // i >> 6
		int bit = i % 64; // i & 63 101010101001010010101011000000

		// += -= *= /= %= &= |= ^= <<= >>= 
    isPrime[element] = isPrime[element] | (1LL << bit);
		isPrime[element] |= (1LL << bit);
	}

	for (int i = 0; i < WORDS; i++) {
		isPrime[i] = 0xFFFFFFFFFFFFFFFFLL;
	}

	for (int i = 2*2; i < n; i+= 2) {
		int element = i / 64; // i >> 6
		int bit = i % 64; // i & 63 101010101001010010101011000000
    isPrime[element] &= ~(1LL << bit); //000000000000001000000000000000
		                                   //111111111111110111111111111111
	}
#endif

	int count = 1; // 2 is prime
	// set all odd numbers true, even numbers false
	for (int i = 0; i < WORDS; i++) {
			isPrime[i] = 0xAAAAAAAAAAAAAAAALL; //   10101010 1010
	}
	const uint64_t lim = sqrt(n);
	for (uint64_t i = 3; i <= lim; i+= 2) {
		if (isPrime[i>>6] & (1LL << (i & 63))) {
			count++;
			// i = 97  97*2 97*3 97*4 97*5 don't bother!
			// i = 3
			// j = 3*3 = 9, 9+6 = 15
			
			for (uint64_t j = i * i; j < n; j += 2*i) { // clear jth bit
				isPrime[j >> 6] &= ~(1LL << (j & 63)); 
			}
		}
	}
	delete [] isPrime;
	cout << "number of primes = " << count << '\n';
	//	int fh = creat("primes.dat", O_RDWR);
}
