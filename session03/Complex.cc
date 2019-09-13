#include <iostream>
using namespace std;

class Complex {


};

int main() {
	const Complex a(1.0, 1.5);
	const Complex b(2.1, -0.5);
	a.print();
	Complex c = a + b;
	Complex d = a - b;
	Complex e = -a;   // (-1.0, -1.5)
	cout << e;
}
