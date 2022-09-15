#include <iostream>
using namespace std;
// in c++, all declarations end in a semicolon

class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d) : num(n), den(d) {}
	void print() const {
		cout << num << '/' << den;
	}
	friend Fraction operator +(Fraction x, Fraction y) {
		return	Fraction(x.num*y.den+y.num*x.den, x.den * y.den);
	}
	
	Fraction operator -(Fraction y) {
		return Fraction(this->num * y.den + y.num * this->den, this->den * y.den);
	}
};


int main() {
	const Fraction a(1,2);
	const Fraction b(1,3);
	Fraction c = a + b;
	Fraction d = a - b;
}

	
