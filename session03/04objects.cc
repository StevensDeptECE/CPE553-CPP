#include <iostream>
using namespace std;
/*
	terms: class, object, method, message

 */
class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d) : num(n), den(d) { // constructor
	} // use the initializer list syntax : num(n), ... better than assignment
	Fraction(int n) { // constructor
		num = n;
		den = 1;
 	}
	Fraction() : num(0), den(1) {
	}
};

int main() {
  Fraction a(1,2);	 //  1/2
  Fraction b(3);	 //  3/1
	// THIS IS NOT AN OBJECT!: Fraction c();
	Fraction c; // calls Fraction::Fraction()

}
