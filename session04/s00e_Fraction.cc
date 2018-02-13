#include <iostream>
#include <fstream>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	Fraction(int n = 0, int d = 1) : num(n), den(d) {
	}

	friend Fraction operator +(Fraction a, Fraction b) {
		return Fraction(a.num*b.den + b.num * a.den, a.den*b.den);
	}
	
	//		a.setNum(1);
	void setNum(int n) {
    num = n;
	}
	
	void setDen(int d) {
		den = d;
	}
	
	void print() const {
		cout << num << '/' << den;
	}
	//			b.print(f);
	void print(ostream& s) const {
		s << num << '/' << den;
	}
	//		const Fraction d = c.neg();
  friend Fraction	operator -(Fraction f) {
		return Fraction(-f.num,f.den);
	}
};

int main() {
	Fraction a;
	a.setNum(1);
	a.setDen(2);
	const Fraction b(1,3);
	b.print();
	ofstream f("test.dat");
	b.print(f);
	const	Fraction c = a + b;
	//		...		b.add(a);
	const Fraction d = -c;
	d.print();
	Fraction e(5);
	//		cout << d;
}
