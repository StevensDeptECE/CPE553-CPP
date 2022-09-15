#include <iostream>
using namespace std;

int main() {
	int a; // variables declared in a function (auto) on the stack, NOT INITIALIZED
	int b = 3;
	int c = 2100000000;
	int d = -2100000000;
	unsigned int e = 4200000000;

	if (e < 0) { // never happen...

	}
  {
		// legacy integer variables
		long a1 = 12345678901L; //literals are constants
		long int a2 = 3; // type promotion
		short a3 = 123; // automatically converts int to short
		// 16 bits   2**16 = 65536
		// -32768 .. 32767
		short int a4 = 32769; // -32767
		signed long long a5 = 123456789012345678LL;
		unsigned long long a5 = 123456789012345678ULL;
		signed char b = 'a'; // 97 0..127

		//c++ also has
		bool george = false;
		george = true;
		george = 19; // don't do this. But it works?
		//anything nonzero is true
		
	}
	{
		//floating point is IEEE754
		// floating point +/-   1.2345678e+23
		// 1.23
		// 12.3
		// 123.
		float f = 1.2345678f; //32 bits
		double f2 = 1.23456789012345;
		long double f3; // more? maybe = double
	}


	{
		// do not use legacy integer types for a new program
		// do not change an existing legacy program without MASSIVE testing
		uint8_t a1 = 255; 
		uint16_t a2;
		uint32_t a3;
		uint64_t a4 = 12314523857192875ULL;

		int8_t a5 = 127;
		int16_t a6 = 32767;
		int32_t a7 = 1;
		int64_t a8 = 1;
	}
		
	for (int i = 1; i <= 10; i++)
		cout << i;

	for (int i = 0; i < 10; i++)
		cout << i;

	//10 9 8 7 6 5 4 3 2 1 0 blastoff!
	for (int i = 10; i >= 0; i--)
		cout << i << ' ';
	cout << "blastoff!";
	
	
	
	
}
