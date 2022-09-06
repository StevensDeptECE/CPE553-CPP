#include "Fraction.hh"

using namespace std;

Fraction::Fraction(int num, int den) : num(num),den(den) {
}

Fraction operator +(Fraction a, Fraction b) {
  return Fraction(a.num*b.den +b.num*a.den, a.den*b.den);
}

ostream& operator <<(ostream& s, Fraction f){
  return s << f.num << '/' << f.den;
}

Fraction Fraction::operator -() const {
  return Fraction(-num, this->den);
}
