
int main() {
	const	Fraction a(1,2);
	const Fraction b(1,3);
	Fraction c = a + b; // use a friend
	cout << c << '\n';
	Fraction d = a - b; // use method
	cout << d << '\n';
	Fraction e = -a; // unary function do this as a method
	Fraction f = a * b; // any way you want....
	cout << f << '\n';
}
