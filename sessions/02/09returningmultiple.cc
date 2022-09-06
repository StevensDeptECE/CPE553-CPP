#include <iostream>
#include <cmath>
using namespace std;

void rect2polar(double x, double y, double& qqq, double& theta) {
  qqq = sqrt(x*x+y*y);
	theta = atan2(y,x);
}



int main() {
	double x = 3.0, y = 5.0;
	// r  theta
	double r,theta;
	rect2polar(x,y, r, theta);
	cout<< r << "\t" << theta << "\n";
	//hw:	polar2rect(r,theta, x,y);
}
