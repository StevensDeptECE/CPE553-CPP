class A {
public:
	void f() { cout << "a"; }
};

class B : public A {
public:
	void f() { cout << "b"; }
};

class C {
public:
	virtual void f() { cout << "c"; }
	virtual ~C() {}   // Scott Meyers Effective C++ (1,2,3)
};

class D : public C {
public:
	void f() { cout << "d"; new int[100]; }
	~D() { delete ... }
};

int main() {
	A a1;
	a1.f(); // a
	B b1;
	b1.f();  // b
	A*p = &a1;
	p->f(); // a
	p = &b1;
	p->f(); // a

	C c1;
	c1.f(); // c
	D d1;
	d1.f(); // d
	d1.C::f(); // c

	C* q = &c1;
	q->f(); // c
	q = &d1;
	q->f() // d

	
