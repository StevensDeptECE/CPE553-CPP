#include <iostream>
using namespace std;

class Fraction {
private:
	int32_t num, den;
public:
	Fraction(int32_t n, int32_t d) : num(n), den(d) {
	}
	Fraction(int32_t n) : num(n), den(1) {
	}
  Fraction() : num(0), den(1) {}
	
	// this
	Fraction add(Fraction b) const { // 1/2+1/3 = 5/6
		// 1/2 + 1/2 = 4/4
		return Fraction(num*b.den + b.num*den, den*b.den);
	}
	// this
	Fraction operator +(Fraction b) const {
		// 1/2 + 1/2 = 4/4
		return Fraction(num*b.den + b.num*den, den*b.den);
	}

	friend Fraction operator -(const Fraction& a, const Fraction& b) {
		return Fraction(a.num * b.den + b.num*a.den, a.den*b.den);
	}
};

int main() {
	const Fraction f1(1,2);
	const Fraction f2(1,3);
	const Fraction f2b(3); // 3/1
	const Fraction f2c; // 0/1
	//THIS IS WRONG, but not an error:  Fraction f2d(); // THIS IS NOT AN OBJECT!!!
	//ERROR: f2d is not an object	cout << 	f2d;
	//ERROR: f2d is not an object f1 = f2d + f2;
	
	Fraction f3 = f1.add(f2);
	Fraction f4 = f1.operator +(f2);
	Fraction f5 = f1 + f2;
	f5 = f1 - f2;
	Fraction f6 = f1 + 3; // automatically calls Fraction(3)  ==> 3/1
	Fraction f7 = 3 + f1;

	
}
