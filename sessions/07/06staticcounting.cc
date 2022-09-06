#include "Person.hh"

void f() {
	Person p("Dov");
	cout << Person::getCount() << '\n';
}

int main() {
	cout << Person::getCount() << '\n';
	f();
	cout << Person::getCount() << '\n';
}
