#include <iostream>
#include <cmath>
using namespace std;

double hypot(double a, double b) {
	return sqrt(a*a + b*b);
}

//const double G = 6.67e-11;
constexpr double G = 6.67e-11;

double grav(double m1, double m2, double r) {
	return G * m1 * m2 / (r*r);
}


int main() {
	cout << hypot(3.0, 4) << '\n';
	double earthmass = 5.972e+24;
	double moonmass = 7.348e+22;
	double dist = 3.8e8;
	cout << grav(earthmass, moonmass, dist) << '\n';
}
	
