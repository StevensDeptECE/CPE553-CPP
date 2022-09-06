#include <iostream>
#include <cmath>
using namespace std;

//f(x) = 2x

int f(int x);

void hello() {
	cout << "hello";
}

//old, ugly c style
void hello(void) {
	cout << "hello";
}

void f(int x) {
	for ( ; x > 0; x--)
		cout << "hello";
}

inline double hypot(double x, double y) {
	return sqrt(x*x + y*y);
}

void rect2polar(double x, double y, double& r, double& theta) {
	r = hypot(x,y);
  theta = atan2(y, x);
}

void rect2polar(double x, double y, double* r, double* theta) {
	*r = hypot(x,y);
  *theta = atan2(y, x);
}

//polar2rect

int main() {
	cout << "Please enter x,y";
	double x, y;
	cin >> x >> y;
	double r, theta;

	rect2polar(x, y, r, theta); // calls the reference one
	rect2polar(x, y, &r, &theta); // calls the pointer one
}





