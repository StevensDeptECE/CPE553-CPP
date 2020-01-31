#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float f = 1.5f; // 1.234567  123.4567  1.23e+32 1.23e-38
	double d = 1.5; // 1.23456789012345  1.234e+308 1.234e-308
	long double ld =  1.345678902345678901234567890L;

	2.5;
	2.5 + 6.022e+23;

	float f2 = 1.234567e+38f;
	float f3 = 1.23e-38f;

	double d2 = 1.23456789012345e+308;
	cout << d2 << '\n';
	cout << setprecision(15) << d2 << '\n';
	cout << setprecision(22) << ld << '\n';

}
