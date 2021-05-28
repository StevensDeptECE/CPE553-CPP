#pragma once
#include <iostream>

class Complex {
private:
	double r, i;
public:
	Complex(double r_, double i_) : r(r_), i(i_) {}
	Complex(double r) : r(r), i(0) {}
	friend Complex add(const Complex& a, const Complex& b);
	Complex add2(const Complex& b) const {
		Complex ans(r + b.r, i+b.i);
		return ans;
	}
	friend Complex operator +(const Complex& a, const Complex& b) {
		Complex ans(a.r + b.r, a.i+b.i);
		return ans;
	}
	Complex operator -(const Complex& b) const {
		Complex ans(this->r + b.r, this->i+b.i);
		return ans;
	}
	friend Complex operator +(const Complex& b) {
		return b;
	}
	Complex operator -() const {
		return *this;
	}
	friend std::ostream& operator <<(std::ostream& s, const Complex& c) {
		return s << '(' << c.r << ',' << c.i << ')';
	}
	void f();
};

