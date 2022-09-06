#include <iostream>

using namespace std;

class complex {
private:
	double real, imag;
public:
	complex(double r, double i) : real(r), imag(i) {}
	friend complex operator + (complex a, complex b) {
		return complex(a.real + b.real, a.imag + b.imag);
	}
	friend complex operator - (complex a, complex b) {
		return complex(a.real - b.real, a.imag - b.imag);
	}
 	friend complex operator * (complex a, complex b) {
		return complex(a.real * b.real - a.imag * b.imag,
									 a.real * b.imag + a.imag * b.real);
	}

 	friend complex operator * (complex a, double s) {
		return complex(a.real * s, a.imag * s);
	}

 	friend complex operator * (double s, complex a) {
		return a * s;
	}

 	friend complex operator - (complex a) {
		return complex(-a.real, -a.imag);
	}
	
	friend ostream& operator <<(ostream& s, complex c) {
		return s << "(" << c.real << "," << c.imag << ")";

	}
};


int main() {
	complex c1(1.5, -0.2);
	complex c2(0.6, 2.1);
	complex c3 = c1 + c2;
	complex c4 = c1 * c2;
	complex c5 = c1 * 2.0;
	complex c6 = -c1;
	complex c7 = 2.0 * c1;
	cout << c3 << ' ' << c4 << ' ' << c5 << ' ' << c6 << '\n';

};
