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

};

/*
x                y
1    /   2    + 1     /     3  = 5 /6
x.num  x.den    y.num       y.den

 */
Fraction operator +(Fraction x, Fraction y) {
	Fraction ans(x.num*y.den+y.num*x.den, x.den * y.den);
	return ans;
}

int main() {
	// all objects must have a unique identity
	//	Fraction f1;
	//	cout << sizeof(f1) << '\n';
	//	cout << sizeof(Fraction) << '\n';
	const Fraction a(1,2);
	Fraction b(1,3);
	Fraction c = a + b;
	a.print();
	cout << '\n';
	b.print();
	cout << '\n';
	c.print();
}

	
