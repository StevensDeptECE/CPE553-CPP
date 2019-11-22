#include "Fraction.hh"
using namespace std;

Fraction::Fraction(int n, int d) : num(n), den(d) {
	count++;
}

Fraction::Fraction(const Fraction& orig) : num(orig.num), den(orig.den) {
	count++;
}

Fraction::~Fraction() {
	count--;
}

Fraction operator +(Fraction a, Fraction b) {
  return Fraction(a.num*b.den + b.num*a.den, a.den*b.den);
}

Fraction Fraction::operator -() const {
  return Fraction(-num, den);
}

Fraction Fraction::neg() const {
  return Fraction(-num, den);
}

ostream& operator <<(ostream& s, Fraction f) {
	return s << f.num << '/' << f.den;
}

int Fraction::count = 0; // turns into extern

int Fraction::getCount() {
	return count;
}
