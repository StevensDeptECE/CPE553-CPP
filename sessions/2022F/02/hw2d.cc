/*
OPTIONAL: NUmerical integration

*/

double f(double x) { return x*x; }
// integrate(0,2)     x*x*x/3   8/3 - 0/3 = 8/3 = 2.666666

int main() {
	trapezoidalIntegration(f, 0.0, 2.0, 0.00001) << "\n";
}
