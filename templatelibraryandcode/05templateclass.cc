#include <iostream>
using namespace std;

template<typename Precision>
class Complex {
	Precision r, i;
public:
	Complex(const Precision& r = 0, const Precision& i = 0) : r(r), i(i) {}
	friend Complex  operator +(const Complex& a, const Complex& b) {
		return Complex(a.r + b.r, a.i + b.i);
	}
	friend ostream& operator <<(ostream& s, const Complex& c) {
		return s << '(' << c.r << ',' << c.i << ')';
	}
};


int main() {
	Complex<double> a(1.5, 2.3);
	Complex<double> b; // b = (0,0)
	Complex<double> c(2.5); // c = (2.5,0)
	auto d = a + b;
	cout << d << '\n';
  Complex<int>  e(1,3);
	//	Complex<double> f = a + e;
	//Complex<Elephant> 
}
