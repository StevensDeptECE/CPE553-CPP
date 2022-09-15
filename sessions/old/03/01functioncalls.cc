#include <iostream>
#include <cmath>
using namespace std;

uint64_t f(uint32_t x) {
	return uint64_t(x)*x;
}

double hypot(double x = 0, double y = 0) {
	return sqrt(x*x + y*y);
}

struct Polar {
	double r, theta;
};

Polar rect2polar(double x, double y) {
	Polar p;
	p.r = sqrt(x*x+y*y);
	p.theta = atn2(y,x);
	return p;
}

void rect2polar2(double x, double y, double& r, double& theta) {
	r = sqrt(x*x+y*y);
	theta = atn2(y,x);
}

void rect2polar3(double x, double y, double* r, double* theta) {
	*r = sqrt(x*x+y*y);
	*theta = atn2(y,x);
}

int main() {
	{
		uint64_t y =  f(3);
		cout << y << '\n';
		y =  f(1000000);
		cout << y << '\n';
	}
	cout << hypot() << '\n';
	cout << hypot(3.5) << '\n';
	cout << hypot(3, 4) << '\n';
	{
		double x = 3, y = 4;
		Point p = rect2polar(x, y);
		cout << p.r << ", " << p.theta << '\n';

		double r, theta;
		rect2polar2(x, y, r, theta); // when this returns r, theta are set
		cout << r << ", " << theta << '\n';

		rect2polar3(x, y, &r, &theta);

		//runtime ERROR		rect2polar3(x, y, nullptr, nullptr);
		//		double*p = nullptr;
		//runtime ERROR rect2polar2(x, y,  *p, *p);
	}
}
