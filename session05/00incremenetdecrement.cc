#include <iostream>
using namespace std;

int main() {
	int a = 2, b = 3;
	a++; // a = 3
	++a; // a = 4
	a = a + 1; // a = 5
	a += 1; // a = 6
	b--; // b = 2

	int c = a++; // c = 6 a = 7
	c = ++a; // a = 8 c = 8
	c = a++ + a++; // impleemntation defined: c = 16 or 17. or hard drive formatted?

	int d = b++ - --a; // 
