#include <iostream>
using namespace std;

class Fraction {
private:
	int num, den;

public:
#if 0 // best way to comment out range of code
  Fraction(int num, int den) : num(num), den(den) {}  /*   */
	Fraction(int n) : num(n), den(1) {}
  Fraction() : num(0), den(1) {}
#endif
	Fraction(int num = 0, int den = 1) : num(num), den(den) {}
	void print() const {
		cout << num << '/' << den;
	}
	friend ostream& operator <<(ostream& s, const Fraction& f) {
    return s << f.num << '/' << f.den;
	}
	friend Fraction operator + (Fraction a, Fraction b) {
		Fraction c(a.num*b.den + b.num*a.den , a.den*b.den);
		return c;
	}
	friend Fraction operator - (Fraction a, Fraction b);
#if 0
	Fraction operator + (Fraction b) {
		return Fraction(num*b.den + b.num*den , den*b.den);
	}
#endif

};
Fraction operator - (Fraction a, Fraction b) {
	Fraction c(a.num*b.den - b.num*a.den , a.den*b.den);
	return c;
}

int main() {
	Fraction a(1,2); // 1/2
	Fraction b(1,3); // 1/3
	Fraction e(5);
	Fraction d;
#if 0
	//	all these are illegal because they don't match
	Fraction f("hello");
	Fraction g("hello", "wednesday");
	Fraction h(1,2,3);
	Fraction f(, 3)
#endif
	const Fraction c = a + b; // 5/6
  cout << "here is my fraction ";	c.print(); cout << "\n";

	cout << c << '\n';
																							 
}
