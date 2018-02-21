#include <iostream>
#include <cmath>
using namespace std;

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
