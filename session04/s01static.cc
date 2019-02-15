#include <iostream>
#include <string>
using namespace std;

class Zebra {
private:
	string name;
  static int count; // shared by the class --> extern
public:
	Zebra(const string& name) : name(name) {
		count++;
		cout << "Hello I'm just born! my name is: " << name << '\n';
	}
	const string& getName() const {
		return name;
	}
	~Zebra() {
		count--;
		cout << "Ugh! I'm dying" << count << "\n";
	}
	static int getCount() { return count; }
};

int Zebra::count = 0;

void f() {
	cout << Zebra::getCount() << '\n';
	Zebra a("Fred"); // now 2 zebra
	Zebra b("Alice"); // 3
	//	cout << a.getCount() << '\n';
	cout << Zebra::getCount() << '\n';
}
int main() {
	cout << Zebra::getCount() << '\n'; // zero!
	Zebra a("Yu-Dong");
	f();
	f();
}
