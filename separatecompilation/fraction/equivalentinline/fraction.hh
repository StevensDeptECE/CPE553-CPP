#pragma once
#include <iostream>

class fraction {
private:
    int num, den;
public:
  fraction(int n, int d) : num(n), den(d) {}

  fraction operator +(const fraction& b) const {
    return fraction(num*b.den+b.num*den, den*b.den);
  }

  fraction operator -() const;
  friend std::ostream& operator<<(std::ostream& s, const fraction& f);
  int getNum() const;
  int getDen() const;
  void setNum(int n);
};