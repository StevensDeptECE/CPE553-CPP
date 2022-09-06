#include <iostream>
using namespace std;

class C {
	int x;
public:
	C(int x) : x(x) {}
	virtual void f() {}
};

class D : public C {
	int y;
public:
	D(int x, int y) : C(x), y(y) {}
	virtual void g() = 0;
};

class F : public D {
public:
	F(int x, int y) : D(x,y) {}
	void f() { cout << "F"; }
};

class G : public F {
public:
	G(int x, int y) F(x,y) {}
	void g() { cout << "G"; }
};

int main() {
	C c1(1,2);// illegal, no matching constructo
	C c2 (2); // legal
	D d1(1,2); // illegal, abstract class
	F f1(1,2); // illegal, inherits g() from D
	G g1(1,2); // LEGAL!
	G g2;
	G* gp = &g1;
	C* cp = &g1;
	g1.g();
	cp->g();
}




	
