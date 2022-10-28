#include <iostream>
# include "bench.hh"
#include <cmath>
using namespace std;

double divideme(double a, double b) {
	return a/b;
}

double f(double x) {
	return 2 * x * 3; // return 6*x;
}
double f2(double x) {
	return x * (3*2); // return 6*x;
}
#if 0
// rearrange so this is faster
void generateCircle(double r, int n) {
	for (int i = 0; i < n; i++) {
		double x = r * cos(2 * i * pi / n);
		double y = r * sin(2 * i * pi / n);
	}
}
#endif

void generateCircle(double r, int n) {
	const double theta = 2 * pi / n ;
	for (int i = 0; i < n; i++) {
		double x = r * cos(theta * i);
		double y = r * sin(2 * i * pi / n);
	}
}


const double G = 6.67E-11;

double Fgrav(double m1, double x1, double y1, double z1,
		double m2, double x2, double y2, double z2) {
			const double dx = x2-x1, dy = y2-y1, dz = z2-z1;
			double dist = sqrt(dx*dx + dy*dy + dz*dz); 
		return G * m1 * m2 / (dist * dist);
		}

// acceleration exerted on the first mass by the secodn
double agrav(double m1, double x1, double y1, double z1,
		double m2, double x2, double y2, double z2) {
	return Fgrav(m1, x1, y1, z1, m2, x2, y2, z2) / m1;
	//return G * m2 / (dist * dist);
}

int main() {
	double c = f3a(2.0, 3.0);
	std::cout << c << '\n';
	//double d = divideme(2.0,3.0);
	//double d = 2.0 / 3.0;
	double d = 0.66666666666;
}
