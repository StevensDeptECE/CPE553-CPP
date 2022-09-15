#include <iostream>
#include <cmath>
using namespace std;

/*
	the compiler cannot inline a function if it does not know what it does
 */
int add(int a, int b); // declaration "function add exists"
int add(int a, int b); // declaration "function add exists"
int add(int a, int b); // declaration "function add exists"
double hypot(double a, double b) {
  return sqrt(a*a + b*b);
}

double min(double a, double b, double c) {
	if (a < b) {
		if (a < c) {
			return a;
		} else {
			return c;
		}
	} else {
		if (b < c) {
			return b;
		} else {
			return c;
		}
	}
}

double max(double a, double b, double c) {
	double temp = a > b ? a : b;
	return temp > c ? temp : c;
}

double disc(double a, double b, double c) {
	return sqrt(b*b - 4 * a * c);
}
//quadratic equation
// -b +/- ..
double root1(double a, double b, double c) {
	return (-b + disc(a,b,c)) / (2*a);
}
double root2(double a, double b, double c) {
	return (-b - disc(a,b,c)) / (2*a);
}



int main() {
  double z = hypot(3, 4); // 5.0

	// REALLY DANGEROUS.  Is this guaranteed?
	cout << (z == 5) << '\n';
	
	cout << z << '\n';
	cout << min(3.0, 4.5, 2.0); // 2.0
	cout << root1(1, 2, 1) << '\n'; // x^2 + 2x + 1
	cout << root2(1, 2, 1) << '\n'; // x^2 + 2x + 1

	cout << root1(1, 2.00001, 1) << '\n'; // x^2 + 2x + 1
	cout << root2(1, 2.00001, 1) << '\n'; // x^2 + 2x + 1
	return 0;
}
