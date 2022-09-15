#include <iostream>
using namespace std;

class A {
	virtual void f() = 0;
	virtual void g() = 0;
};

class B : public A {
	void f() { cout << "b"; }
};

class C : public B {
	void g() const { cout << "c"; }
};


int main() {
	A a1; // abstract class Cannot instantiate
	A a2(); // legal but it is not an object of type A, it  is a FUNCTION
	A a3(3);
	A* ap;
	const A* ap2;
	A * const ap3; // constant pointer must be initialized
	
	B b1; // still abstract (g)

	C c1; // still abstract




	








	
