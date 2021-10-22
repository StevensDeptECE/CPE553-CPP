class Complex { // -2 class Complex {
private: // private: not needed, default
	double real, imag;
public:
  Complex(double r, double i) : real(r),imag(i) {}
  Complex(double r, double i) {
		real = r; imag = i;
	}
	friend Complex  operator +(Complex x, Complex y) {
		return Complex(x.real + y.real, x.imag + y.imag);
	}
	Complex operator -() const {
    return Complex(-real,-imag);		
	}
	Complex add(Complex right) const {
		return *this + right;
		//		return Complex(real + right.real, imag + right.imag);		
	}
	friend ostream&  operator <<(ostream& s, Complex c) {
    return s << "(" << c.real << "," << c.imag << ")";
	}
}; // -0.5 to forget ;


int prod(int a[], int first, int last) {
	int p = 1;
	for (int i = first; i <= last; i++) {
		p *= a[i];
	}
	return p;
}

