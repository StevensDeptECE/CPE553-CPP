#include <iostream>
using namespace std;

int main() {
	int x[] = {1, 3, 5, 9, 2, 7};
	int y[10] = {5, 3, 2};
	int* p = &x[2];
	*p++ = 19;
	*p-- = 21;
	--*p;
	p = &y[1];
	for (int i = 0; i < 5; i++, p++)
		++*p;

	for (int i = 0; i < sizeof(x) / sizeof(int); i++)
		cout << x[i] << ' ';
	cout << '\n';

	for (int i = 0; i < sizeof(x) / sizeof(int); i++)
		cout << y[i] << ' ';
	cout << '\n';
		
