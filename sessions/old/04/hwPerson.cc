int main() {
	Person a("Dov", "Kruger");
	Person b("Min", "Song");
	cout << a << '\n';
	cout << b << '\n';
	cout << Person::getCount() << '\n';
}
