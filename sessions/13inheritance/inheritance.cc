class A {
private:
	int x;
protected:
	int y; // this class and its children can see
public:
	A() : x(0) {}
	void f() { cout << 'a'; } // everyone can see this
};

class B : public A {
private:
	int x;
protected:
	int y;
public:
	void f() { cout << 'b'; }
	B() : A(), A::y(2), x(1), y(3) {}
};

B b1;
b1.f(); // calls B's method f
b1.A::f(); // calls A's


class Heart {
private:
	int bpm;
protected:
	int systolic;
public:
	Heart(int bpm, int systolic, int diastolic) {}
};

// Person IS_A heart, but no one needs to know that
class Person : private Heart {
};

// Every person has a heart hidden inside
class Person {
private:
	Heart h;

};

// A PErson IS_A heart, but no one on the outside needs to know,
// only children of Person
class Person : protected Heart {
};

// this is illegal, not because it doesn't make sense, but because it must be invisible to outsiders
Heart* h = new Person();
h->getBPM();

INSTEAD:

class Person {
protected:
	Heart h;
};



// an interface in C++
class F {
public:
	virtual void f() = 0;
};

F f1; // this is illegal, can't instantiate
f1.f(); // therefore this can never happen

class AbstractClass : public F {
private:
	int x;
public:
	AbstractClass(int x) : x(x) {}
};

AbstractClass a(2); // can't instantiate because f

class MyClass : public AbstractClass {
public:
	void f() override  {

	}
}
