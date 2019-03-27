#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() const = 0;
	virtual ~Base() {}
};

class A : public Base {
private:
	int* p;
public:
	A() {
		p = new int[10];
		cout << "A()";
	}
	~A() {
		delete [] p;
		cout << "~A()";
	}
	void f() const { cout << "hello!"; }
};

class B : public Base {
private:
	int* q;
public:
	B() {
		q = new int[15];
		cout << "B()";
	}
	~B() {
		delete [] q;
		cout << "~B()";
	}
	void f() const { cout << "bye!"; }
};

int main() {
	Base* array[2];
	array[0] = new A();
	array[1] = new B();

	for (int i = 0; i < 2; i++)
		delete array[i];
}
