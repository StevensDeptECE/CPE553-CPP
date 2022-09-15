#include "Fraction.hh"
using namespace std;

int Fraction::count = 0;

Fraction::Fraction(int n) : num(n), den(1) {}

Fraction::Fraction() : num(0), den(1) {}

Fraction operator +(Fraction a, Fraction b) {
  return Fraction(a.num*b.den+b.num*a.den,a.den*b.den);
}

ostream& operator <<(ostream& s, Fraction f) {
	return s << f.num << '/' << f.den;
}
