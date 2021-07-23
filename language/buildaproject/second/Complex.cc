#include "Complex.hh"
#include <iostream>
using namespace std;

Complex add(const Complex& a, const Complex& b) {
	Complex ans(a.r + b.r, a.i+b.i);
	return ans;
}

void Complex::f() {
	cout << "yo!";
}
