#include <iostream>
using namespace std;

class A {
public:
	void f() const {
		g();
	}
	void g() {
		cout << "hello";
	}
};

int main() {
	A a1;
	a1.g();
	a1.f();
}
