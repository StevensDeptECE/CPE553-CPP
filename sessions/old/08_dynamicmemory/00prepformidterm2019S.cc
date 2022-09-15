#include <iostream>
#include <cstdint>

using namespace std;
class Bitmap {
private:
	uint32_t width, height;
	uint32_t* p;
public:
	Bitmap(uint32_t w, uint32_t h) : width(w), height(h),
																	 p(new uint32_t[width*height]())
	{
		//		for (int i = 0; i < w*h; i++)
		//			p[i] = 0;
	}
	~Bitmap() { delete [] p; }
	void drawHorizontal(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
		for (uint32_t i = x1; i <= x2; i++) {
			p[y*width+ i] = color;
		}
	}
};

int main() {
	Bitmap b(400,300);
	const uint32_t RED = 0xFF0000;
	b.drawHorizontal(0, 100, 50, RED);

}
#if 0
2.
class A {
public:
	A()      { cout << 'a'; }
	A(int x) { cout << 'b'; }
	~A()     { cout << 'c'; }
};

class Y {
public:
	Y() { cout << 'h'; }
	~Y() { cout << 'i'; }
};
class X : public Y {
private:
	A a1,a2;
public:
  X(int v) : a1(), a2(v) { cout << 'd'; }
	~X() { cout << 'e'; }
};

void f() {
	X x1(3);    // habdecci
}

X x2(2); // global variable is initialized BEFORE main, destroyed AFTER main
int main() { // habd qhabdeccir ecci
	cout << 'q';
	f();
	cout << 'r';
}


#if 0

class A {
public:
	virtual void f() const = 0;
	virtual ~A() = 0;
};

class B : public A {
private:
	int x;
	B(int x) : x(x) { cout << 'a'; }
	~B() { cout << 'b'; }
	void f() const { cout << 'c'; }
	void g() const { cout <<"THIS DOES NOT EXIST in C"; }

};

class C : public A {
private:
	int y;
	C(int y) : y(y) { cout << 'd'; }
	~C() { cout << 'e'; }
	void f() const { cout << 'f'; }
};
int main() {
	C c1(8); //_________________
	c1.f();

	B b1(2);
	b1.f();
	A* p = &c1; // base class pointer may point to derived class
	B* q = &b1;
	q->f();
	p = &b1;
	//	q = &c1;  ILLEGAL: These are not compatible classes
	//	q->g(); ILLEGAL: This method g() does not exist in C

#endif
