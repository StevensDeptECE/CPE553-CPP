#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
	return x*x - 2;
}
double bisection(double a, double b) {
	double x,y;
	do {
		x = (a + b) / 2;
		y = f(x);
		if (y > 0)
			b = x;
		else if (y < 0)
			a = x;

	}while(abs(b - a) > .000000000001);
	return a;
}

int main()  {
#if 0
	for (float x = 0.0; x <= 100; x += 0.1) {
		cout << x <<  ' ';
	}

	float x = 0.0;
	for (int i = 0; i <= 1000; i++, x += 0.1) {
		cout << x << ' ';
	}
	#endif
	cout << setprecision(15) << bisection(1,2) << '\n';
		
  float t1 = 70.0000f;
	float t2 = 70.0001f;
	float delta = t2-t1; // 0.1xxx
	//-b + sqrt(b*b-4*a*c)
}
