#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;
double doubleMe(double x) { return x*2; }
// double sin(double)
// double cos(double)
// double sqrt(double)

double integrate(double (*f)(double x), double a, double b, uint32_t n) {
	double sum = 0;
	double h = (b - a) / n;
	double x = a;
	for (uint32_t i = 0; i <= n; i++, x += h)
		sum += f(x);
	return sum * h;
}



typedef double (*FuncOneVar)(double x);

double trap(FuncOneVar f, double a, double b, uint32_t n) {

	double h = (b - a) / n;
	double sum = (f(a) + f(b)) / 2;
	double x = a+h;
	for (uint32_t i = 1; i < n; i++, x += h)
		sum += f(x);
	return sum * h;
}



int main() {
	int a;
	int* p = &a;


	float b;
	//	p = &b; // ERROR

	float* q = &b;
	const double pi = 3.14159265358979;
	cout << integrate(sin, 0, 2*pi, 16) << '\n';
	cout << integrate(sin, 0, 2*pi, 1024) << '\n';
	cout << trap(sin, 0, 2*pi, 4) << '\n';
	cout << trap(sin, 0, 2*pi, 8) << '\n';
}
