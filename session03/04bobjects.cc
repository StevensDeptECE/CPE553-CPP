#include <iostream>
using namespace std;
/*
	terms: class, object, method, message

 */
class Fraction {
private:
	int num, den;
public:
	Fraction(int n = 0, int d = 1) : num(n), den(d) { // constructor
	}
	void print() {
		cout << num << '/' << den;
	}
	friend Fraction add(Fraction a, Fraction b);
	friend Fraction operator +(Fraction a, Fraction b);

 	Fraction add(Fraction b) {
		Fraction ans(this->num*b.den + b.num*this->den, (*this).den * b.den);
		return ans;
	}
#if 0
 	Fraction operator +(Fraction b) {
		Fraction ans(this->num*b.den + b.num*this->den, (*this).den * b.den);
		return ans;
	}
#endif
	
};

/*
     a       b
num=  1       1     
	   --- +   --- = ----
	    2       3     6
 */


Fraction add(Fraction a, Fraction b) {
	Fraction ans(a.num*b.den + b.num*a.den, a.den * b.den);
	return ans;
}

Fraction operator +(Fraction a, Fraction b) {
	Fraction ans(a.num*b.den + b.num*a.den, a.den * b.den);
	return ans;
}

int main() {
  Fraction a(1,2);	 //  1/2
  Fraction b(3);	 //  3/1
	Fraction c; // calls Fraction::Fraction()
	a.print();
	c = a; // operator = is automatically defined (memberwise copy)
	c = add(a,b);
	c = a.add(b);
	c = a + b;
	//	cout << 5 << " hello " << a << '\n';
}
