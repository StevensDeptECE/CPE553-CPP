#include <iostream>
#include <cmath>

using namespace std;

double sq(double x) { return x*x; }

// FuncOneVar is a pointer to functions that take one double parameter
// and return double
typedef double (*FuncOneVar)(double);

void eval(FuncOneVar f, double a, double b, int n) {
	double h = (b - a) / n; // cut the interval a to b into n slices
	double x = a;
	for (int i = 0; i <= n; i++, x += h)
		cout << x << '\t' << f(x) << '\n';
}

int main() {
	cout << "sq\n";
	cout << sq(3) << '\n'; // sq(3) = 3*3 = 9
	eval(sq, 0.0, 3.0, 3);

	cout << "\n\nsin\n";
	const double PI = 3.1415926535897932;
	eval(sin, 0.0, 2*PI, 6);
	
}
