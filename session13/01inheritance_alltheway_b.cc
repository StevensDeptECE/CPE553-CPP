class A {
	friend class X;
private:
	int x;
protected:
	int y;
	void f();
public:
	int z;
	void g() { cout << x << y << z; }
	A(int x) x(x), y(0), z(3) {}
};

class B : public A { // public in A --> public in B
	//private in A is INSIDE B, but we can't see it. (invisible)
	//protected in A is still protected
public:
	void h() {
		f();
	}
	B() : A(2) {}
};

class C : public B{
public:
	void k() {
		f();
	}
};

int main() {
	B b1;
	b1.g();
	b1.f(); // is protected, only visible inside B
}
















