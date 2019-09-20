// add class Complex here...

int main() {
	// Main() Section 1
	Complex a(2.5, 1.0); // double precision
	Complex b(1.2, 2.3);
	
	// Main() Section 2
	Complex c = a + b;
	Complex d = a - b;
	Complex e = -a;
	
	// Main() Section 1
	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	cout << "a + b = " << c << '\n';
	cout << "a - b = " << d << '\n';
	cout << "-a: " << e << '\n';
}
