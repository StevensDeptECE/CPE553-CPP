#include "Fraction.hh"

Fraction::Fraction(int n, int d) : num(n), den(d) {}
  
Fraction Fraction::operator +(const Fraction& b) const {
    return Fraction(this->num*b.den + b.num * this->den, this->den * b.den);
}

std::ostream& operator <<(std::ostream& s, const Fraction& f) {
    return s << f.num << "/" << f.den;
}
