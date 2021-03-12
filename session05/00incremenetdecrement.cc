#include <iostream>
using namespace std;

int main() {
	int a = 2, b = 3;
	a++; // a = 3
	++a; // a = 4
	a = a + 1; // a = 5
	a += 1; // a = 6
	b--; // b = 2

	int c = a++; // c = 6 a = 7  int c = a; a++;
	c = ++a; // a = 8 c = 8
	
	//	int j = ++i + (k - 3) * ++m; // read that, sucker
//	c = a++ + a++; // implementation defined: c = 16 or 17. or hard drive formatted?
	// similar:	c = ++a + ++a;

	int d = b++ - --a; // a=7 d=2-7 = -5   b = 3 
