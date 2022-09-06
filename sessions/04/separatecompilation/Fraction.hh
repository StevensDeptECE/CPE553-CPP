#include <iostream>

class Fraction {
private:
  int num, den;
	static int count;
public:
	Fraction(int n, int d) : num(n), den(d) {}
	Fraction(int n);
	Fraction();
  friend Fraction operator +(Fraction, Fraction);
	// for member operator, this points to first operand
	//	Fraction operator +(Fraction) const ;
  friend std::ostream& operator <<(std::ostream& s, Fraction f);	
};
