#include <iostream>
#include <cmath>
using namespace std;

/**
 * Accept any function of one double parameter returning double, and 
 * invoke the function for f(a), f(a+h), f(a+2h), f(a+3h)... f(b).
 * where h = (b-a) / n
 *
 */
double sum(double *f(double), double a, double b, int n) {
	double s = 0;
	double dx = (b - a) / n;
	double x = a;
	for (int i = 0; i < n; i++, x += dx) {
		s += f(x);
	}
	return s;
}

int main() {
	cout << sum(sin, 0, 2*M_PI, 32) << "\n";
}
