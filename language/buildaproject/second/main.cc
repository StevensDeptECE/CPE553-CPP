#include <iostream>
#include <unistd.h>
using namespace std;
#include "Complex.hh"

int main() {
	Complex a(1.0, 2.2);
	Complex b(3.0); // imag defaults to zero
	Complex c = add(a,b); // friend function
	Complex d = a.add2(b); //method
	Complex e = a + b; // friend binary operator
	Complex f = a - b; // binary member operator
	Complex g = +f;  // g=f? unary operator friend
	Complex h = -f;  // unary operator - member
	//	cout << c;
	c.f();

	Complex* p = &a;
	//	(*p).r = 99;
	//	p->r = 99;

  for (int i = 0; i < 10000; i++) {
		cout << 'x';
		usleep(10000);
	}
		
}
