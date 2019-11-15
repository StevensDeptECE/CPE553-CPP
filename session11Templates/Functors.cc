#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

class DoubleMe {
public:
	double operator ()(double x) { return 2*x; }
};


template<typename FuncOneVar>
double trap(FuncOneVar f, double a, double b, uint32_t n) {

	double h = (b - a) / n;
	double sum = (f(a) + f(b)) / 2;
	double x = a+h;
	for (uint32_t i = 1; i < n; i++, x += h)
		sum += f(x);
	return sum * h;
}



int main() {
	DoubleMe dm;
	cout << trap(dm, 0, 3, 4) << '\n';
	cout << trap(dm, 0, 3, 8) << '\n';
}
