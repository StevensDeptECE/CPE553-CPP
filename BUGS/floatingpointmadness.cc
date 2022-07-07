#include <iostream>
#include <iomanip>
using namespace std;

/*
	Intel used to have 80 bits in-register, 64 in memory
	making results from unoptimized code different than optimized
	(Optimized was more correct, if the values were kept in-register)
	Can this still be replicated given that new hardware uses vector
	registers with 128 and 256 bits, with each number only 64 bits max?

	depends on whether gcc -march= can specify an old architecture
	pre-sse and what they do with it.

	gcc -march=x86-64
 */
void variablePrecision() {
 	float a = 0;
	for (int i = 1; i <= 100; i++)
		a += 1.0/i;
	cout << "forward float: " << setprecision(16) << a << '\n';
	a = 0;
	for (int i = 100; i > 0; i--)
		a += 1.0/i;
	cout << "backward float: " << setprecision(16) << a << '\n';
 	double b = 0;
	for (int i = 1; i <= 100; i++)
		b += 1.0/i;
	cout << "forward double: " << setprecision(16) << b << '\n';
	b = 0;
	for (int i = 100; i > 0; i--)
		b += 1.0/i;
	cout << "backward double: " << setprecision(16) << b << '\n';
}

void	testcentroiddouble() {
	double xy[] = {

	};
}


void testcentroidfloat() {
	float xy[] = {

	};

}
void testcentroidDelta() {
	float xy[] = {

	};
	const uint32_t n = sizeof(xy)/sizeof(float);
	float basex = xy[0], basey = xy[1];
	for(int i = 0; i < n; i += 2) {
		xy[i] -= basex;
		xy[i+1] -= basey;
	}
	Point center = centroid(xy, n);
	cout << center << '\n';
}

int main() {
	variablePrecision();
	testcentroiddouble();
	testcentroidfloat();
	testcentroidDelta();
	centroid();
}

