#include <iostream>
using namespace std;

#include "Fraction.hh"

int main() {
	const Fraction a(1,2); // 1/2
	Fraction b(3);   // 3/1
	Fraction c;      // 0/1
	//c2 is not an object!!!	Fraction c2();
	Fraction d  = a + b;
	cout << d << '\n';
	cout << Fraction::getCount();
}
