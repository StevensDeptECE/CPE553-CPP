#include <iostream>
#include <cmath>
using namespace std;

/*
	x^17 = x^1x^16
  x^16 = (X^8)^2
  X^8 = (X^4)^2
  X^4 = (X^2)^2
  X^2 = X^2

  n = 513 = 1000000001

 */
double power(double x, int n) {
	double prod = 1;
	while (n > 0) {
		if (n % 2 != 0) // if n is ODD
			prod *= x;
		x *= x; // x squared, x^4, x^8, ...
		n /= 2;
	}
	return prod;
}


double hypot(double a, double b) {
	return sqrt(a*a + b*b); // pow(a,2)  --> a*a
	//NOT A GOOD IDEA:	return pow(a*a+b*b,0.5);// not as good as sqrt
}

int main() {
	double c = hypot(3.0, 4.0);
  cout << c << '\n';
	cout << power(2.0, 17);
}
