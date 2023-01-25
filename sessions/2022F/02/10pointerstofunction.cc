#include <iostream>
#include <cmath>
using namespace std;

double f1(double x) { return x*x-7; } // when x = sqrt(7) root!
double f2(double x) { return x*x*x-3; } // when x = cube root of 3


double bisection(double (*f)(double x), double a, double b, double eps) {
	//	double y1 = f(a);
	//	double y2 = f(b);
	double x;
	while (abs(b-a) > eps) {
		x = (a+b)/2;
		cout << a << '\t' << b << '\n';
		double y =	f(x);
		if (y < 0)
			a = x;
		else if ( y > 0)
			b = x;
		else
			return x;
	}
	return (a + b) /2;
}
int main() {
	cout << bisection(f1, 0, 5, .001) << "\n";
	cout << bisection(f1, 1, 4.5, .000001) << "\n";
	cout << bisection(f2, 0, 2.2, .0001) << "\n";
	cout << bisection(sin, -1, 1.2, .0001) << "\n";
}
