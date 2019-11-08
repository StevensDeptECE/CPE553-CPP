#include <iostream>
using namespace std;

class A { // object-oriented: parent   c++: base class
public:
	void f() { cout << "a"; }
};

class B : public A { // object-oriented: child, inherits from A, is a kind of A, c++: derived class
public:
	void f() { cout << "b"; }
};

class C { // how much bigger is C than A?
public:
	virtual void f() { cout << "c"; }
};

class D : public C {
public:
	void f() { cout << "d"; }
};

class E { // object-oriented: abstract class  contains at least one PURE VIRTUAL function
public:
	virtual void f() = 0;
};

class F : public E {
public:
	void f() { cout << "f"; }
};

class G : public E {
public:
	void f() { cout << "g"; }
};

int main() {
	A a1;
	a1.f();
	B b1;
	b1.f();
	b1.A::f(); // call the one in my parent

	A* p;
	p = &a1;
	p->f(); // calls A::f() 'a'
  p = &b1;
	p->f(); // calls A::f()

	C c1;
	c1.f(); // calls C::f()
	D d1;
	d1.f(); // calls D::f();
	C* q = &c1;
	q->f();  // calls C::f()
	q = &d1;
	q->f();  // calls D::f() THIS IS DIFFERENT BECAUSE OF virtual

	cout << "\n\n";
	cout << sizeof(A) << "\n";
	cout << sizeof(C) << "\n";

	// ERROR: Cannot instantiate E: 	E e1;
	E e2();
	E* p2; // creating a pointer is ALWAYS LEGAL
	// illegal: Cannot instantiate abstract class E:	p2 = new E();
	p2 = new F();
	//  ILLEGAL: TYPES DO NOT MATCH	p2 = new B();
  p2->f(); // F::f()
	delete p2;

	p2 = new G();
	p2->f(); // G::f()
	
	delete p2;

}

	
