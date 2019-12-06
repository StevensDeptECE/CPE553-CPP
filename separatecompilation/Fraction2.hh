#pragma once

#include <iostream>
class Fraction {
private:
  int num, den;
	static int count; // turns into extern
public:
	Fraction(int n, int d) {}
	friend Fraction operator +(Fraction a, Fraction b);
	Fraction operator -() const;
	Fraction neg() const;
	friend std::ostream& operator <<(std::ostream& s, Fraction f);
};


