#include <iostream>
using namespace std;

/*
	class is a specification of an object  
	object  is an instance of a class (an example of a class)
	message 
	method     = member functions

key features
encapsulation: hide the internals
 */


class Fraction {
private:
	int numerator, denominator;
public:
  Fraction(int n, int d) {	// constructor
		numerator = n;
		denominator = d;
	}
	void print() {
    cout << numerator << "/" << denominator;
	}
};


int main() {
	Fraction f1(1,2); // 1/2
	Fraction f2(1,3);
	f1.print();
	cout << "\n";
	f2.print();
	//	Fraction f3 = f1 + f2;

}
