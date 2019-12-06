class A {
};
class B : public A {
public:
	B(int x) { cout << "B"; }
	~B() { cout << "~B"; }
	void f() { cout << "f"; }
};
class C : public B {
public:
	C(int x, int y) : B(x) { cout << y; }
	~C() { cout << "~C"; }
	void f() { cout << "g"; }
};

int main() {
	A a1;        // LEGAL default A()
	A a2(2);    // ILLEGAL: no matching constructor
	B b1;        // ILLEGAL: no matching constructor
	B b2(2);    // LEGAL
	b2.f();       // "f"
	C c1(1,2); // LEGAL
	c1.f();       // "g"
	c1.B::f();  // "f"  not on a test, but good trivia
	A* ap = &b2; // LEGAL
	ap->f();      // ILLEGAL
	ap = &c1;  //
	ap->f();      // ILLEGAL
	cout << sizeof(a1) << '\n'; // 1? 8?
	//cout << sizeof(a2) << '\n';
	cout << sizeof(b1) << '\n'; // 1? 8? (not bigger)
}
