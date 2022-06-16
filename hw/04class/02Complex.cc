int main() {
	const Complex a(1.5,2.1);  // create a Complex number 1.5 + 2.1i
	const Complex b(1.7,-1.2); // create a Complex number 1.7 - 1.2i
	Complex c = a + b;        // add them = 2.2 - 0.9i
	const Complex d = a * b;        // multiply them
	cout << d << '\n';
	const Complex e = -d;
	cout << e << '\n'; // compute the negative 
}
