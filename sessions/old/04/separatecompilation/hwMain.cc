int main() {
	const Fraction a(1,2); // 1/2
	Fraction b(3);   // 3/1
	Fraction c;      // 0/1

	//use both friend and member operators
	Fraction d  = a + b;
	Fraction e  = a - b;
	Fraction f = -a;
	Fraction g = a.add(b);
	cout << d << '\n';
	cout << e << '\n';
	cout << f << '\n';
	cout << g << '\n';
	cout << Fraction::getCount() << '\n'; // how many
}
