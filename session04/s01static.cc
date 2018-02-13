#include <iostream>
#include <string>
using namespace std;

class Zebra {
private:
	string name;
	static int count; // shared by the class
public:
	Zebra(const string& s) : name(s) {
		count++;
		cout << "Hello I'm just born! my name is: " << name << '\n';
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
	Zebra a("Fred"); // now 1 zebra
	Zebra b("Alice"); // 2
	//	cout << a.getCount() << '\n';
	cout << Zebra::getCount() << '\n';
}
int main() {
	f();
	f();
}
