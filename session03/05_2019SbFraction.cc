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
	friend Fraction operator +(Fraction x, Fraction y);
	// this points to the object receiving the message
	Fraction add(Fraction y) {
		return	Fraction(this->num*y.den+y.num*this->den, this->den * y.den);
	}

};

Fraction operator +(Fraction x, Fraction y) {
  return	Fraction(x.num*y.den+y.num*x.den, x.den * y.den);
}

Fraction add(Fraction x, Fraction y) {
  return	Fraction(x.num*y.den+y.num*x.den, x.den * y.den);
}

int main() {
	// all objects must have a unique identity
	//	Fraction f1;
	//	cout << sizeof(f1) << '\n';
	//	cout << sizeof(Fraction) << '\n';
	const Fraction a(1,2);
	Fraction b(1,3);
	Fraction c = a + b;
	Fraction d = add(a,b);
	Fraction e = a.add(b);
	a.print();
	cout << '\n';
	b.print();
	cout << '\n';
	c.print();
}

	
