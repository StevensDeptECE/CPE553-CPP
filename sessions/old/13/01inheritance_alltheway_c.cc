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

class B : private A { // public in A --> private
public: // protected in A is now --> private
	void h() { // private in A (invisible)
		f();
	}
	B() : A(2) {}
};
//alternatively:
class B {
private:
	A hidden;
	
};

int main() {
	B b1;
	b1.g(); // illegal, g is private
	b1.f(); // is PRIVATE
}
















