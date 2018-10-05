#include "Matrix.hh"

int main() {
	Matrix m1(3, 4, 0.0); // create a 3 x 4 matrix filled with zeros
	m1(1,1) = 1.0;
	m1(0,2) = 2.5;
	m1(2,3) = 1.5;
	double x[] = {
		1.0, 2.5,
		2.0, 3.0,
		-1.0, 1.5,
		0.5, -2.5
	};
	Matrix m2(4, 2, x); // and a 4 x 2 matrix filled with the above
	Matrix m3 = m1 * m2; // multiply matrices
	cout << m1 << '\n';
	cout << m2 << '\n';
	cout << m3 << '\n';
}
