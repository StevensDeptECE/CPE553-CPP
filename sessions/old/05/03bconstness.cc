#include <iostream>
using namespace std;

int main() {
	int a = 2;
	const int*p = &a; // p is a READONLY pointer
	cout << *p;
	a = 3; // a can change
	cout << *p << '\n';

	const int b = 3;
 	//int * q = &b; // illegal
	//	*q = 2;
	int*q = (int*)&b;
	*q = 2;
	cout << b << '\n';

	const double pi = 3.14159265358979;
	double *dp = (double*)&pi;
	*dp = 4;
	cout << &pi << '\n';
	cout << dp << '\n';
	cout << *dp << '\n';
}
