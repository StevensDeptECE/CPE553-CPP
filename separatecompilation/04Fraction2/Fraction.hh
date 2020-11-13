#pragma once

#include <iostream>

class Fraction {
private:
  int num, den;
public:
	Fraction(int num, int den): num(num),den(den) {
	}

	// bogus method f, just for illustrative purposes
 	void f();
	
	friend Fraction operator +(Fraction a, Fraction b);
	friend std::ostream& operator <<(std::ostream& s, Fraction f);
};
