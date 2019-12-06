#include "Fraction.hh"
using namespace std;
void f() {
	Fraction a(1,5);
	cout << Fraction::getCount() << '\n';
}

int main() {
	cout << Fraction::getCount() << '\n';
	Fraction a(1,2);
	Fraction b(1,3);
	Fraction c = a + b;
	Fraction d = -a;
	Fraction e = a.neg();
	f();
	cout << Fraction::getCount() << '\n';
	cout << c;
}
