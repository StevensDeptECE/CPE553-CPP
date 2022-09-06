#include <iostream>
using namespace std;

class Fraction {
private:
	uint32_t num, den;
public:
	Fraction(uint32_t n, uint32_t d) : num(n), den(d) {
	}
	Fraction(uint32_t n) : num(n), den(1) {
	}

	friend Fraction operator +(Fraction a, Fraction b) {
		return Fraction(a.num*b.den + b.num*a.den, a.den*b.den);
	}
};

int main() {
	Fraction f1(1,2);
	Fraction f2(1,3);
	Fraction f3 = f1 + f2;
	Fraction f4 = f1 + 2; // f1 + Fraction(2) = f1 + 2/1
	Fraction f5 = 2 + f1; // Fraction(2) + f1
}
