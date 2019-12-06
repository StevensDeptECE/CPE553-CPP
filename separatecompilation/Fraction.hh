#ifndef FRACTION_HH_
#define FRACTION_HH_
#include <iostream>

class Fraction {
private:
  int num, den;
	static int count; // turns into extern
public:
	Fraction(int n, int d);
	Fraction(const Fraction&);
	~Fraction();
	friend Fraction operator +(Fraction a, Fraction b);
	Fraction operator -() const;
	Fraction neg() const;
	friend std::ostream& operator <<(std::ostream& s, Fraction f);
	static int getCount();
};
#endif

