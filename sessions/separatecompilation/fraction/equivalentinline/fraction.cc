#include "fraction.hh"
using namespace std;


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