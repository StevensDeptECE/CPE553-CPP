#ifndef FRACTION_HH_
#define FRACTION_HH_

//note: always include whatever header files you need. Do not assume it will be included for you
#include <iostream>

class fraction {
private:
	int num, den; // we must know how big the class is. All data must be specified
public:
	// header file contains function prototypes (declarations) of all methods
	// could eventually also have inline code. We will discuss that later
	fraction(int n, int d);
	int getNum() const;
	
	friend operator +(fraction a, fraction b);

	// note: full names on data types in header files (std::ostream)
	// because you have no control over what else will be included
	std::ostream& operator <<(std::ostream& s, fraction f);
};
