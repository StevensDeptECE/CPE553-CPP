#include <iostream>
using namespace std;

int main() {
	// +   -  *  /  %
	int a = 2;
	int b = 3;
	int c = a * b; // multiplication is slower than +
	int d = b * 8; // multiply by a power of 2
	// b = 0000000000011 in binary   shift left  110
	// left shift by 1 = multiply by 2
	// 9240 add a zero in decimal means * 10
	int e = b << 3; // 1 clock cycle (this is what the optimizer does

	int f = 23;
	int g = f >> 2;  // 0000010111 = 00000101   = 5
	cout << g;
	/*
		0   0000
		1   0001
		2   0010
		3   0011
		4   0100
		5   0101
		6   0110
		7   0111
		8   1000
		9   1001
		A   1010
		B   1011
		C   1100
		D   1101
		E   1110
		F   1111

	 */

	int a = 0xFC25;           //    1111 1100 0010 0101
	int b = 0x3E9A;           //    0011 1110 1001 1010
	cout << ~a << '\n';       //    0000 0011 1101 1010  0x03DA
	cout << (a & b) << '\n'; // AND 0011 1100 0000 0000 
	cout << (a | b) << '\n'; // OR  1111 1110 1011 1111 0xFEBF
	cout << (a ^ b) << '\n'; // XOR 1100 0010 1011 1111 0xC2BF
}
