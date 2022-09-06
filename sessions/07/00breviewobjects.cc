#include <iostream>
using namespace std;

class A {};
class B {
private:
	int x;
public:
	B(int x) : x(x) {}
	B() : x(-3) {}
	void f() { cout << "hello"; }
};

int main() {
	A a1; // _________________
	B b1;
	B b2(3);
	B b3();
	b3.f(); //ILLEGAL: b3 is not an object
}
