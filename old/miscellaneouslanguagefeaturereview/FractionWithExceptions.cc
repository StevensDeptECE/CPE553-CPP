#include <iostream>
using namespace std;

// design principle: Stop bad data before it gets into your object
// never let your object get into a bad state
class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d) : num(n), den(d) {
		if (d == 0)
			throw "divbyzero";
	}
  friend Fraction operator +(Fraction a, Fraction b) {
		return Fraction(a.num*b.den+a.den*b.num, a.den*b.den);
	}
};

// if no catch is found, program calls terminate() --> abort()
int main() {
	Fraction a(1,0);
	Fraction b(2,3);
	Fraction c = a + b;

}
