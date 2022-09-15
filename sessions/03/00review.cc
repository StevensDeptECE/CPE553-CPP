#include <iostream>
#include <cstdint>
#include <numbers> // C++20
#include <cmath>
using namespace std;

int main() {
	int a; // a= random number
	uint8_t b = 255;
	cout << (b + 1) << '\n'; // 256
	b++;   // b= 0
	int c = 3 / 4 ; // c=0
	double  d = 3 / 4; // first integer / 3/4-> 0  --> 0.0  d = 0.0

	int x1, x2;
	cin >> x1 >> x2;
	double d2 = x1 / x2;

	int e = 3 % 4 + 4 % 4 + 5 % 4; // e = 3+1 = 4
	double f = 2.0 / 5; // 5 --> 5.0    2.0 / 5.0 = 0.399999999999999999999
	// 0.5
	// 1/5 = 0.2  10 % 5 == 0
	// 1/3 = .3333333333  10 % 3 != 0

	// low/high = 0/1
	// .00010100101001
	double g = 3 / 2 * 2.0; // g = 2.0
	double g2 = 2 / 3 * 2.0; // g = 0.0
	int h = 3 + 4 * 5; // 23
	int h2 = (3 + 4) * 5; // 35

	bool b1 = 3 < 2; // false = 0
	bool b2 = 2 < 3 && 3 != 6; // true
	bool b3 = 2 > 3 || 2 > 1; // true
	bool b4 = 2 + 2 == 4; // true
	bool b5 = 2.0 + 3.0 == 5; // true
	//	bool b6 = 0.1 + 0.1 + 0.1 == 0.3;
	double sum = 0;
	for (int i = 0; i < 10; i++)
		sum += 0.1;

#if 0
	// DO NOT DO THIS!!!
	bool b6 = sum == 1.0; // false NEVER DO THIS
	bool b7 = sum != 1.0;; // true  NEVER DO THIS
#endif

	// this is how equality works in floating point
	bool b6 = abs(sum - 1.0) < 0.0000001; // approximately equal

	// NEVER USE FLOAT

	bool b7 = cos(M_PI/4) == sqrt(2)/2; //false
	//	bool b7 = abs(cos(M_PI/4) - sqrt(2)/2) < 0.00000001; // approximate
	std::cout << std::numbers::pi;
	
	// write sum (1.. n)
	constexpr int n = 100;

	uint32_t sum = 0;
	for (uint32_t i = 1; i <= n; i++)
		sum += i;

	uint32_t prod = 1;
	for (uint32_t i = 1; i <= n; i++)
		prod *= i;

	
		
	
}
