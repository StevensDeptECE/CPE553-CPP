class Complex {
private:
  double r, i;
public:
	Complex(double r = 0, double i = 0) : r(r), i(i) {}
	Complex operator +(const Complex& b) const {
		return Complex(this->r + b.r, i + b.i);
	}
	Complex operator -() const {
		return Complex(-r, -i);
	}
};


int main() {
	const Complex c1(1.5,-2.0);
	const Complex c2; // (0,0)
	const Complex c3 = c1 + c2; // c1.operator+(c2)
  const Complex c4 = -c1;
	//	cout << c3;
}
