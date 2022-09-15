#include <iostream>
#include <cmath>
using namespace std;

void rect_to_polar(double x, double y, double& r, double& theta) {
	r = sqrt(x*x+y*y);
	theta = atan2(y,x);
}

// this form is better because it's obvious that you are changing r and theta
// at the call site
void rect_to_polar(double x, double y, double* r, double* theta) {
	*r = sqrt(x*x+y*y);
	*theta = atan2(y,x);
}

void minmax(int a, int b, int& min, int& max) {
  if (a < b) {
		min = a;
		max = b;
	} else {
		min = b;
		max = a;
	}
}

void minmax(int& a, int& b) {

}

int main() {
	double x = 3, y = 4;
	double r, theta;
  rect_to_polar(x, y, r, theta); // C++ using reference
	rect_to_polar(x, y, &r, &theta); // C using pointers

	int min, max;
  int a = 2, b = 3;
	minmax(a, b, min, max);
	cout << min << " " << max << "\n";
}
