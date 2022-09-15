#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;

// root = x = sqrt(2) +/-
double f(double x) { return x*x - 2; }
typedef double (*FuncOneVar)(double x);

double bisection(FuncOneVar f, double a, double b, double eps) {
	double y1 = f(a), y2 = f(b);
	if (y1 * y2 > 0)
		throw  "Root might not be there";

	double mid;
	do {
		mid = (a + b) / 2;
		double y = f(mid);
		if (y > 0)
			b = mid;
		else if (y < 0)
			a = mid;
	} while (abs(b - a) > eps);
	return (a+b)/2;
}

class F1 {
public:
	double operator()(double x) { return x*x - 2; }
};

class F2 {
public:
	double operator()(double x) { return x*x*x - 2; }
};

template<typename FunctionOneVar>
double bisection2(FunctionOneVar f, double a, double b, double eps) {
	double y1 = f(a), y2 = f(b);
	if (y1 * y2 > 0)
		throw  "Root might not be there";

	double mid;
	do {
		mid = (a + b) / 2;
		double y = f(mid);
		if (y > 0)
			b = mid;
		else if (y < 0)
			a = mid;
	} while (abs(b - a) > eps);
	return (a+b)/2;
}


int main() {
	const int n = 10000000;
	clock_t t0 = clock();
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += bisection2(f, 0, 3, 0.000001);
	clock_t t1 = clock();
	cout << (t1 - t0) << '\n';
	
#if 0
	cout << set
		precision(15);
	cout << bisection(f, 0, 3, 0.01) << '\n';
	cout << bisection(f, 0, 3, 0.00001) << '\n';
	cout << bisection(f, 0, 3, 1e-9) << '\n';
	cout << bisection(f, 0, 3, 1e-14) << '\n';
#endif
}
