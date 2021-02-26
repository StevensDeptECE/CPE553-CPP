#include <iostream>
#include <fstream>
using namespace std;

int a;
const double x = 5;


class Fraction {
private:
	int num, den;
public:
	//Fraction a;
	Fraction() : num (0), den(1){ // 0/1
	}
	//		Fraction e(5);
	Fraction(int n) : num(n), den(1) { // 5/1
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
	
	void print() const { // C++: this is a member function
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
	Fraction a; // Fraction is a type, a is an object of that type (an instance of that type)
	a.setNum(1);
	a.setDen(2);
	const Fraction b(1,3);
	b.print(); // sending a message to b, which responds by executing a method (O-O terminology)
	ofstream f("test.dat");
	b.print(f);
	const	Fraction c = a.add(b);
	//		...		b.add(a);
	const Fraction d = c.neg();
	d.print();
	Fraction e(5);
	//		cout << d;
}
