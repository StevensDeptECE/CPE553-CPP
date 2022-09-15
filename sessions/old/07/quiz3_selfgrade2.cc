#include <iostream>
using namespace std;

class C {
	int x;
public:
	C(int x) : x(x) {}
	virtual void f() = 0;
};

class D : public C {
	int y;
public:
	D(int x, int y) : C(x), y(y) {}
};

class F : public D {
public:
	F(int x, int y) : D(x,y) {}
	void f() { cout << "F"; }
};

int main() {
	C c1;
	C c2(3);
	C c3(int x);
	C* cp; // It is ALWAYS legal to declare a pointer
	D d1;
	D d2(1,2);
  d1.f();
	F f1(1,2);
	f1.f();
}




	
