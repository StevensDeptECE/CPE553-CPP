#include <iostream>
using namespace std;
/*
	Author: Dov Kruger
	cite: I got help from the whole class to do this!

	n-bits = 2**n
        unsigned    signed
	000 =  0             0
	001 =  1             1
	010 =  2             2
	011 =  3             3
	100 =  4            -4
	101 =  5            -3
	110 =  6            -2
	111 =  7            -1
    1
  ===
 1000
 */
int main() {
	int a = 1 + 2;
	int b = 1 - 2;
	unsigned int c = 1 - 2;
	int d = 1000000000 + 2000000000;
	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';

	int e = 2 * 3;
	int f = 1000000 * 1000000;
	cout << e << ' ' << f << '\n';
	cout << 50 * 365 * 24 * 60 * 60 << '\n';
	cout << 68 * 365 * 24 * 60 * 60 << '\n';
	cout << 69 * 365 * 24 * 60 * 60 << '\n';
	cout << 70 * 365 * 24 * 60 * 60 << '\n';
}
