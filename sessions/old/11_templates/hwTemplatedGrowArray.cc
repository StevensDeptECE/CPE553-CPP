#include "GrowArray.hh"

int main() {
	GrowArray<int> a(1000);
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	cout << a << '\n';// 0 1 2 3 4 5 6 7 8 9
	for (GrowArray<int>::Iterator i = a; !i; ++i)
		cout << *i * 2 << ' ';
	cout << '\n';   // 0 2 4 6 8 10 12 14 16 18
	
	GrowArray<string> b;
	a.addEnd("hello");
	a.addEnd("yo!");
	a.addEnd("testing");
	cout << b << '\n';
	for (GrowArray<string>::Iterator i = b; !i; ++i)
		cout << *i + "a" << ' '; // helloa yo!a testinga

	GrowArray<Person> c(100);
	c.addEnd(Person("Name", 23)); // name and age
	c.addEnd(Person("Name", 21)); // name and age
	cout << c;
}
