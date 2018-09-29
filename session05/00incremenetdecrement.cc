#include <iostream>
using namespace std;

int main() {
	int a = 2, b = 3;
	a++; // a = 3
	++a; // a = 4
	b--; // b = 2

	int c = a++; // c = 4,  a = 5
	c = ++a; // a = 6  c = 6

	int d = b++ - --a; // a = 5   d = 2 - 5 = -3   b = 3
