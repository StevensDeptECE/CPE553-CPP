class Complex {
private:
  double r, i;
public:
	Complex(double r = 0, double i = 0) : r(r), i(i) {}
  friend	Complex operator +(const Complex& a, const Complex& b) {
		return Complex(a.r + b.r, a.i + b.i);
	}
	friend Complex operator -(Complex a) {
		return Complex(-a.r, -a.i);
	}
  friend ostream& operator <<(ostream& s, Complex c) {
		return s << "(" << c.r << "," << c.i << ")";
  }
};


int main() {
	const Complex c1(1.5,-2.0);
	const Complex c2; // (0,0)
	const Complex c3 = c1 + c2; // c1.operator+(c2)
  const Complex c4 = -c1;
  cout << c3 << '\n';
}
