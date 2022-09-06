#include "fraction.hh"
using namespace std;

fraction::fraction(int n, int d) : num(n), den(d) {
}


fraction fraction::operator +(const fraction& b) const {
  return fraction(num*b.den+b.num*den, den*b.den);
}


fraction fraction::operator -() const {
  return fraction(-num, den);
}

ostream& operator<<(ostream& s, const fraction& f) {
   return s<< f.num << "/" << f.den;
}

int fraction::getNum() const {
   return num;
}

int fraction::getDen() const {
  return den;
}

void fraction::setNum(int n) {
  num = n;
}