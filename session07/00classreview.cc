#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  string firstName, lastName;
	int age;
public:
	Person(const string& fname = "John", const string& lname = "Doe", int age = 0)
		: firstName(fname), lastName(lname), age(age) {}
	friend ostream& operator <<(ostream& s, const Person& p) {
		return s << "Person firstname=" << p.firstName << " lastname=" << p.lastName <<
			" age=" << p.age;
	}
};

int main() {
	Person a("Steve", "Rogers", 60);
	Person b("Steve", "Rogers");
	Person c("Steve");
	Person d;

	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	cout << d << '\n';
}
