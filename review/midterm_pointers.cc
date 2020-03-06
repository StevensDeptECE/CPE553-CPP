#include <iostream>
using namespace std;

int main() {
	int a = 2;
	const int b = 3;
	// bad idea: const int c;
	int* p = &a;
	int*p2;
	p2 = &a;
	*p = 99; // a = 99  *p is an alias for a
	*p2 = 98;
	//ILLEGA: p = &b;
	const int * q = &b; // promise to only read b
	//	*q = 88;
	p = (int*)&b;
	*p = 99;
	cout << b << '\n';
	const double PI = 3.14159265358979;
	cout << & PI  << '\n';
	double* dp = (double*)&PI;
	cout << dp << '\n';
	*dp = 4;
}
