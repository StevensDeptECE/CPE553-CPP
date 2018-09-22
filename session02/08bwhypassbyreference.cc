#include <iostream>

//r, theta = rect2Polar(x, y)

void rect2Polar(double x, double y, double&r, double&theta) {
  r = sqrt(x*x+y*y);
	theta = atan2(y,x);
}

// for homework
void polar2Rect(double r, double theta, double&x, double& y) {
}

int main() {
	double x = 3, y = 4;
	double r, theta;
	rect2Polar(x, y, r, theta);
	cout << r << " " << theta << '\n';
}
