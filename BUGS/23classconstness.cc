class A {
private:
	int x;
public:
	A() const { x = 5; }
	void f() const { x = 6; }
	void g() { cout << x; }
};

int main() {
	A a1;   // a1 may change
	a1.f(); // set x to 6
	a1.g(); // print out a1

	const A a2; // this a2 should not change.
	a2.f(); // set a2 to 6
	a2.g(); // print out a2
}
