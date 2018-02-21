class A {
private:
	int x;
public:
	A() { x = 5; }
	void f() const { g(); } // all f does is call the method g!  What's wrong?
	void g() { cout << x; }
};

int main() {
	A a1;   // a1 may change
	a1.f();
}
