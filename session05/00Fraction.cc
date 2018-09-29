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

	// this
	Fraction add(Fraction b) { // 1/2+1/3 = 5/6
		// 1/2 + 1/2 = 4/4
		return Fraction(num*b.den + b.num*den, den*b.den);
	}
	// this
	Fraction operator +(Fraction b) {
		// 1/2 + 1/2 = 4/4
		return Fraction(num*b.den + b.num*den, den*b.den);
	}
};

int main() {
	Fraction f1(1,2);
	Fraction f2(1,3);
	Fraction f3 = f1.add(f2);
	Fraction f4 = f1.operator +(f2);
	Fraction f5 = f1 + f2;
	Fraction f6 = f1 + 3; // automatically calls Fraction(3)  ==> 3/1
	Fraction f7 = 3 + f1;

	
}
