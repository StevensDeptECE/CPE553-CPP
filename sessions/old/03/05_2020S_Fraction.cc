#include <iostream>
#include <fstream>
using namespace std;

class Fraction {
public:
	// always prefer to use initializer list
	Fraction(int n, int d) : num(n), den(d)  {  }
	Fraction(int n) : num(n), den(1) {}
	Fraction() : num(0), den(1) {}
	void print() const 	{
		cout << num << "/" << den;
	}

	void print(ostream& s) const {
		s << num << "/" << den;
	}
	int getNum() { return num; }
	//	void setNum(int n) { num = n; }
	int getden() { return den; }
	//	void setDen(int d) { den = d; }

	/*this points to the object on the left, r is the right
			\                                   /
			 \                                 /
			  num=1                           num=1
				den=2                           den=3
				                                r.num
        this->num                       r.den
				 num
				 den

				 1    1 
				 2    3     = 6

	 */
	Fraction add(Fraction r) const {
		return Fraction(num*r.den+r.num*den , den * r.den  );
	}

	// member operator (binary, left side = this)
	Fraction operator +(Fraction r) const {
		return Fraction(num*r.den+r.num*den , den * r.den  );
	}

	// member operator (unary, ONLY side = this)
	Fraction operator -() const {
		return Fraction(-num,den)  );
	}

// friend operator binary
	//	friend Fraction operator +(Fraction left, Fraction right) {
	//		return Fraction(left.num*right.den+right.num*left.den , left.den * right.den  );
	//	}

// friend operator unary
//	friend Fraction operator -(Fraction right) {
//	return Fraction(-right.num, right.den);
//}

	friend ostream& operator <<(ostream& s, Fraction f);
private:
	const int num, den;
};

ostream& operator <<(ostream& s, Fraction f) {
  s << f.num << '/' << f.den;
	return s;
}

int main() {
  const	Fraction a(1, 2); // 1/2 // a is an object, an instance of Fraction
	Fraction b(1, 3);
	Fraction c(-6, 5); // -6/5
	Fraction d(7, -5);
	Fraction e(1,0);
	Fraction f(3);
	Fraction g;
	a.print();
	b.print();
	Fraction h = a.add(b);
	Fraction h2 = a + b;
	int x = 2 + 3;
	ofstream s("test.dat");
	a.print(s);
	cout << a;
	//	cout << 6 << "hello" << a << 
}
