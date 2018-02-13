#include <iostream>
#include <fstream>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	//Fraction a;
	Fraction() : Fraction(0,1) { // 0/1
	}
	//		Fraction e(5);
	Fraction(int n) : Fraction(n,1) { // 5/1
	}
	
	//		const Fraction b(1,3);
	Fraction(int n, int d) : num(n), den(d) {
	}

	//		const	Fraction c = a.add(b);
	Fraction add(const Fraction r) const {
		// left hand side = this
		return Fraction(num*r.den + r.num * den, den*r.den);
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
  Fraction	neg() const {
		return Fraction(-num,den);
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
	const	Fraction c = a.add(b);
	//		...		b.add(a);
	const Fraction d = c.neg();
	d.print();
	Fraction e(5);
	//		cout << d;
}
