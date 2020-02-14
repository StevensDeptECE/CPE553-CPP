#include <iostream>
using namespace std;

class Fraction {

	operator double() const { return  double(num) / den;  }
};
int main() {
	Fraction a(1,2);
	Fraction b(1,3);
	Fraction c = a + b;
	Fraction d = a - b;
	Fraction e = a * b;
	Fraction f = a / b;
	Fraction g = a.power(3);
	Fraction h = a.power(b);
	Fraction j = -a; // -2/3  --> 2/3  2/3 --> -2/3
	if (a == b) {
	}
	// if you don't want to handle separate cases for negative denominators....
	// never let them happen... stop in the constructor 2/-3 --> 2/3
	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	// ...
}
