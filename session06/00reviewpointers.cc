#include <iostream>

int main() {
	int a = 2;
	int& r = a; // r is an alias for a
	cout << r << '\n';
	cout << &r << '\n';

	int x[] = {5, 3, 1, 8};
	int*p = &x[0];
	*p++ = 2; // x[0] = 2, p = &x[1]
	*p-- = 5; // x[1] = 5, p = &x[0]
	--*p;     // x[0] = 1
	*++p = 3; // x[1] = 3;
	int* q = x;
	for (int i = sizeof(x)/sizeof(int); i > 0; i--)
		cout << *q++;

}
