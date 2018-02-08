/*
	Make the following main work by writing a class Complex.
	In this second version you will overload operator << and use the friend syntax
	
	Replace this comment with your author information and cite as necessary.
 */
#include <iostream>



int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using friend
	Complex d = -c; // use friend
	cout << c << '\t' << d << '\n';
}
