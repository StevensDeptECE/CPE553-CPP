class A {
public:
	A(int x) {}
};

class B : public A {
public:
	B(int x) : A(x) {}
};

void f() {
	A a(5);
	B b(2);
}


