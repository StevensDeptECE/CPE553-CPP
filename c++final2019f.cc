#include <iostream>
#include <cmath>
using namespace std;
class A {
private:
  int x;
public:
  A() : x(3) { cout << 'A'; }
  A(int x) : x(x) { cout << 'B'; }
  ~A() { cout << 'C'; }
};
class B : public A {
private:
  int y;
public:
  B() : A(), y(2) { cout << 'D'; }
  B(int x, int y) : A(x), y(y) { cout << 'E'; }
  ~B() { cout << 'F'; }
};
class C {
private:
  B b1, b2;
public:
  C(int x1, int y1, int x2, int y2)
		: b1(x1,y1), b2(x2,y2) { cout << 'G'; }
  ~C() { cout << 'H'; }
};

void printeq(double v) {
  cout << (v == v ? "equal" : "not equal") << '\n';
}
bool f() {
  cout << "yo!";
  return false;
}
bool g() {
  cout << "ho!";
  return true;
}

class D {
public:
  virtual void f() = 0;
  virtual void g() {
		cout << 'd';
	}
};
class E : public D {
public:
  void f() override {
    cout << 'a';
  }
  void g() override {
		cout << 'e';
	}
};
class F : public D {
public:
  void f() override {
    cout << 'b';
  }
};

class G : public F {
public:
  void f() override {
    cout << 'c';
  }
};

class H {
public:
  void f() {
    cout << 'd';
  }
};

class J : public H {
public:
  void f() {
    cout << 'e';
  }
};


int main() {
  //arithmetic operators
  cout << ((3 / 4  + 5) / 4 + 6) * 2 << '\n';   //____________________________
  cout << 3 % 4 + 4 % 4 + 5 % 4 << '\n';        //____________________________
  cout << 4 % 3 + 3 % 4 << '\n';                //____________________________
  cout << 5 % 3 * 3 << '\n';                    //____________________________

  // casting
  cout << (int)2.5 * 3 << '\n';                 //____________________________
  cout << int(2.5 * 3) << '\n';                 //____________________________
  cout << (int)((3 / 2 * 2) / 3.0) + 1 << '\n'; //____________________________

  // bitwise operators
  cout << (1 << 3) << '\n';                     //____________________________
  cout << (6 & 5) << '\n';                      //____________________________
  cout << (6 | 5) << '\n';                      //____________________________
  cout << (6 ^ 5) << '\n';                      //____________________________
  cout << (69 & 31) << '\n';                    //____________________________

  //ternary operator
  cout << (2 < 3 ? 4 : 5) << '\n';              //____________________________
  

  //rules of INFINITY and NaN
  double x = 1.0 / 0.0;
  cout << x << '\n';                            //____________________________
  cout << 2*x << '\n';                          //____________________________
  cout << -x << '\n';                           //____________________________
  cout << -x+x << '\n';                         //____________________________
  cout << 1/x << '\n';                          //____________________________
  cout << sqrt(x) << '\n';                      //____________________________
  cout << sin(x) << '\n';                       //____________________________
  //floating point equality for special values
  printeq(x);                                   //____________________________
  printeq(sin(x));                              //____________________________

  //short-circuiting
  if (f() && g())
    cout << "hello\n";                          //____________________________
  if (g() || !f())
    cout << "hello\n";                          //____________________________
  if (g() && f())
    cout << "hello\n";                          //____________________________
  //structure packing rules and sizes
  struct A {
    char a;
    uint32_t b;
    char c;
    double d;
  };
  cout << sizeof(char) << '\n';                 //____________________________

	// rearrange A to be more efficient....
#if 0
	struct A {
		char a, c; // 2 bytes wasted
		uint32_t b;
    double d;
	};
#endif
  cout << sizeof(uint32_t) << '\n';             //____________________________
  cout << sizeof(A) << '\n';                    //____________________________


  // loop logic
  uint32_t sum = 3;
  for (int i = 0; i < 10; i++)
    if (i % 3 == 0)
      sum += 2 * i;
  cout << sum << '\n';                          //____________________________

  //floating point
  double sum2 = 0;
  double f = 1;
  for (int i = 0; i < 5; i++, f *= 0.5)
    sum2 += f;
  cout << sum2 << '\n';                         //____________________________

	{
		// inheritance
		C c1(1,2, 3,4);                               //____________________________
		cout << '\n';
	}

	{
		E e1;
		e1.f();                                       //____________________________
		D* d = &e1;
		d->f();                                       //____________________________
		d->g();                                       //____________________________
		F f1;
		d = &f1;
		d->f();                                       //____________________________
		d->g();                                       //____________________________
		cout << '\n';
	}

	{
		H h1;
		h1.f();
		J j1;
		j1.f();
		H* h = &j1;
		h->f();                                       //____________________________
		cout << '\n';
	}
  // pointer madness
  int y[10] = { 5, 2, 9, 6};
  int* p = y + 3;
  ++*(p-1);
  p++;
  p[2] += 3;
  for (int i = 0; i < 10; i++)
    cout << y[i] << ' ';
  cout << '\n';                                 //____________________________
}

