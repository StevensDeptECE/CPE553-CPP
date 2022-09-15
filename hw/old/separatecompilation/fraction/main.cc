#include "fraction.hh"

int main() {
	fraction a(1,2);
	fraction b(1,3);
	fraction c = a + b;
	fraction d = a - b;
	fraction e = -a;
	cout << c << '\n';
	cout << d << '\n';
	cout << e << '\n';
}
