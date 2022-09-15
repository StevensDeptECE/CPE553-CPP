#include <iostream>
using namespace std;

int main() {
	const double PI = 3.14159265358979;
	//	PI = 4;
	//	double* p = &PI;
	cout << &PI << '\n';
	double* p = (double*)&PI;
	cout << p << '\n';
	*p = 4;
	cout << PI << '\n';
}
