#pragma once
#include <iostream>

class fraction {
private:
	int num, den;
public:
	fraction(int n, int d);
	// binary operator a+b
	friend fraction operator +(fraction a, fraction b);

	// binary operator a-b
	friend fraction operator -(fraction a, fraction b);

	// unary operator -a
	friend fraction operator -(fraction a);

	friend std::operator <<(std::ostream& s, fraction f);
};
