#include <iostream>

//r, theta = rect2Polar(x, y)

void rect2Polar(double x, double y, double& c, double&ang) {
  c = sqrt(x*x+y*y);
	ang = atan2(y,x);
	x = 99;
}

// for homework
void polar2Rect(double r, double theta, double&x, double& y) {
}

int main() {
	double x = 3, y = 4;
	double r, theta;
	rect2Polar(x, y, r, theta);
	cout << x << ' ' << y << '\n'; // x is still 3!!
	cout << r << " " << theta << '\n';
}
