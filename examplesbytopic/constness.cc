#include <
class A {
private:
	int x;
	int y[1024];
public:
	A() : x(0) {}
	void print() const {
		cout << this->x;
	}
  void setX(int x) const{
		this->x = x;
	}
};

class Fraction {
	int num, den;
public:

	Fraction(int n) : num(n), den(1) {}
	friend Fraction operator  +(Fraction x, Fraction y) {

	}
	Fraction operator -(Fraction b) const {

	}
	friend ostream& operator <<(ostream& s, Fraction f);
	ostream& operator <<(ostream& s);
};

ostream& operator <<(ostream& s, Fraction f){
	return s << f.num << '/' << f.den;
}
int main() {
	const A a1;
	a1.print();
	const Fraction a(1,2);
	const Fraction b(1,3);
	Fraction c = a + b;
	Fraction d = a - b;
	cout << a;
	Fraction e(3); // 3/1

	Fraction f1 = a + 3; // a + Fraction(3)
	Fraction f2 = 3 + a; // Fraction(3)+ a
	Fraction f3 = a - 3; // a - Fraction(3)
	Fraction f4 = 3 - a; // DOES NOT WORK
}
