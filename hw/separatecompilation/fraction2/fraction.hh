#pragma once
#include <iostream>

class fraction {
private:
	int num, den;
public:
	fraction(int n = 0, int d = 1);
	// binary operator a+b
	fraction operator +(fraction b) const;

	// binary operator a-b
	fraction operator -(fraction b) const;

	// unary operator -a
	fraction operator -() const;

	friend std::operator <<(std::ostream& s, fraction f);
};
