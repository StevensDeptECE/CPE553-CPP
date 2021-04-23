#include <iostream>
#include <iomanip>
using namespace std;

template<typename Precision>
class Complex {
private:
	Precision r,i;
public:
	Complex(Precision r, Precision i) : r(r), i(i) {} // Complex<Precision>::Complex
  friend Complex operator +(Complex a, Complex b)	{
    return Complex(a.r+b.r, a.i+b.i);
	}

	friend Complex operator -(Complex a, Complex b)	{
    return Complex(a.r-b.r, a.i-b.i);
	}
friend ostream& operator <<(ostream& s, Complex c) {
		return s << '(' << c.r << ',' << c.i << ')';
	}
};

int main() {
	Complex<double> c1(1.1, 2.1);
	cout << setprecision(18) << c1 << '\n';
	Complex<double> c2(2.1, 1.2);
	Complex<double> c3 = c1 + c2;

	Complex<float> c4(1.1f, 2.1f);
	cout << setprecision(8) << c4 << '\n';

	Complex<long double> c5(1.1L, 2.1L);
	cout << setprecision(21) << c5 << '\n';
	cout << sizeof(c1) << '\n';
	cout << sizeof(c4) << '\n';
	cout << sizeof(c5) << '\n';

	// this does not make any sense!
	Complex<string> c6("a", "b");
	Complex<string> c7("c", "d");
	Complex<string> c8 = c6 + c7; // "ac" "bd" legal though!
	
	//Complex<string> c9 = c6 - c7; // "ac" "bd" legal unless you try subtraction...
}		
