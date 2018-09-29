#include <iostream>
using namespace std;
class A {
public:
	//A() {}  //default constructor
};

class Fraction {
private:
	uint32_t num, den;
public:
	Fraction(uint32_t n, uint32_t d) : num(n), den(d) {
		int g = gcd(n, d);
		if (g > 1) {
			num /= g;
			den /= g;
		}
	}
	friend Fraction operator +(Fraction a, Fraction b) { // 1/2+1/3 = 5/6
		// 1/2 + 1/2 = 4/4
		return Fraction(a.num*b.den + b.num*a.den, a.den*b.den);
	}
	friend Fraction operator -(Fraction a, Fraction b) {
		return Fraction(a.num*b.den - b.num*a.den, a.den*b.den);
	}
	friend Fraction operator -(Fraction a) {
		return Fraction(-a.num, a.den);
	}
};

int main() {
	int32_t x;
	cout << sizeof(char) << '\n';
	cout << sizeof(x) << '\n';
	A a1; //identity principle
	A a2;
	cout << sizeof(a1) << '\n';
	//  Fraction f1;
	Fraction f1(1,2);
	cout << sizeof(Fraction) << '\n';
	Fraction f2(2,3);
	Fraction f3 = f1 + f2;
	Fraction f4 = -f1;
}
