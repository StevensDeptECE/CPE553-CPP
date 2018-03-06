#include "Fraction.hh"
using namespace std;


Fraction::Fraction(int n, int d)
	: num(n), den(d) {}

Fraction operator *(Fraction a, Fraction b) {
	return Fraction(a.num*b.num, a.den*b.den);
}

ostream& operator <<(ostream& s, Fraction f) {
	return s << f.num << "/" << f.den;
}
