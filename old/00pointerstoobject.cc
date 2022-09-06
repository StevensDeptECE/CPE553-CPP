class A {
public:
	virtual void f() = 0;
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

void f() {
	A* ap = new B(2); // "B"
	ap->f(); // "f"
	ap = new C(1,2);  // "B2"
	ap->f(); // "g"
	B b1(3); //B
	delete ap; // ~C~B
}

int main() {
	f();
}
