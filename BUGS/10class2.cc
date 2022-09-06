#include <iostream>
using namespace std;

class A {
private:
public:
	A()      { cout << "constructor"; }
	void f() { cout << "f"; }
};
	
int main() {
	A a1();
	a1.f();
}
