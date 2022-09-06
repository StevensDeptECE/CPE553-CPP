#pragma once

#include <iostream>

template<typename Precision>
class Complex {
private:
  Precision r,i;
public:
	Complex(Precision r, Precision i) {}
	friend Complex<Precision> operator +(const Complex<Precision>& a, const Complex<Precision>& b);
	friend std::ostream& operator<<(std::ostream&s, const Complex<Precision>& c);
};
