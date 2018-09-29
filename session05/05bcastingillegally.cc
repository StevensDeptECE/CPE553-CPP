#include <iostream>
using namespace std;

int main() {
	const double PI = 3.14159265358979;
	//	PI = 4;
	//	double* p = &PI;
	double* p = (double*)&PI;
	*p = 4;
	cout << PI << '\n';
}
