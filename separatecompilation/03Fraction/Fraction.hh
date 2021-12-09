#ifndef FRACTION_HH_
#define FRACTION_HH_

#include <iostream>

class Fraction {
private:
  int num, den;
public:
	Fraction(int num, int den);
	friend Fraction operator +(Fraction a, Fraction b);
	friend std::ostream& operator <<(std::ostream& s, Fraction f);
	Fraction operator -() const; 
};
#endif
