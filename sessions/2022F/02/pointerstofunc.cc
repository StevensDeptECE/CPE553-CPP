#include <iostream>
#include <cmath>  // double sin(double), double cos(double)
using namespace std;

constexpr double PI = 3.14159265358979;

double f(double x) { return x*x; }
//x*x*x/3 
typedef double (*FuncOneVar)(double);

double integrate(FuncOneVar f, double a, double b) {
	double ya = f(a), yb = f(b);
	double mid = (a + b) / 2;
	double ymid = f(mid);
	return (0.5*(ya + yb) + ymid)* (b-a);
}
	//double integrate(double (*f)(double), double a, double b, eps) {
int main() {
	cout <<	integrate(f, 0.0, 2.0) << '\n';; // 8/3 - 0
	cout <<	integrate(sin, 0.0, 2.0*PI)<< '\n';; // 8/3 - 0
}
