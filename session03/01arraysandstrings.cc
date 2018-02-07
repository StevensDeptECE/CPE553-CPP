#include <string>
#include <iostream>
using namespace std;

int main() {
	int a;
	int b[] = {1,2,3}; // b[0], b[1], b[2]
	int c[4]; // random garbage (if zero, we are just LUCKY!!)
	int d[5] = {3, 2, 1}; // last two are zero
	int e[100] = {0}; // first one is zero, and so are all the rest
	for (int i = 0; i < 3; i++) // should not hardcode 3, but ok...
		cout << b[i]; // prints 123
	for (int i = 4; i >= 0; i--)
		cout << d[i]; // 00123
}
