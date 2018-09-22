// add class Complex here...

int main() {
	Complex a(2.5, 1.0); // double precision
	Complex b(1.2, 2.3);
	Complex c = a + b;
	Complex d = a - b;
	Complex e = -a;
	a.print();
	cout << a << " + " << b << " = " << c << '\n';
	cout << a << " - " << b << " = " << d << '\n';
	cout << "-" << a << " = " << e << '\n';
}
