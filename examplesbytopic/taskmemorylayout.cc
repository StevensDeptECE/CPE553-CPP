#include <iostream>
#include <iomanip>
using namespace std;
int x = 0;
const int y = 0;
const char s[] = "this is a test of constant initialized data";
class A {
private:
public:
	static int shared;
	virtual void f();
};

void A::f() {
	cout << "code here";
}

class B {
private:
public:
	static int shared;
	virtual void f();
};

void B::f() {
	cout << "more code here";
}

int A::shared = 22;
int main() {
	cout << hex;
	cout << "Main:\t" << (void*)main << "\n";
	cout << "x:\t" << &x << "\n";
	cout << "y:\t" << &y << "\n";
	double piapproxonstack = 3.1415;
	cout << "piapproxonstack:\t" << &piapproxonstack << "\n";
	const double PI = 3.14159265358979;
	A a1;
	B b1;
	cout << "PI on stack:\t" << &PI << "\n";
	cout << "&a1:\t" << &a1 << '\n';
	cout << "A VFT:\t" << *(void**)&a1 << '\n';
	cout << "B VFT:\t" << *(void**)&b1 << '\n';
	cout << "A::f():\t" << (void*)&A::f << '\n';
	cout << "B::f():\t" << (void*)&B::f << '\n';
	cout << "A::shared:\n" << &A::shared << '\n';
}
