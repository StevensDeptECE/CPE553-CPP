#include <iostream>
using namespace std;

int main() {
	int x[10] = {5, 4, 3, 2, 1}; // the name x points to first element
	int* p = x;
	p = &x[0];
	for (int i = 7; i > 0; i--)
		cout << *p++; // prints 5432100
	cout << '\n';
	for (int i = 6; i > 0; i--)
		cout << *--p; // prints 001234
	cout << '\n';
}
