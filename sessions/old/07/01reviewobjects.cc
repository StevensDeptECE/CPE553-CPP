#include <iostream>
using namespace std;

class A {
public:
  void f() { cout << "yo!"; }
};
int main() {
  A a1;          // ________________
  A a2();        // ________________
  A* p;          // ________________
	const A a3;
	p = &a1;
	p = &a3;       // ILLEGAL: a3 is const
  const A* q;    // ________________
	q = &a3;
  A* const r;    // ILLEGAL: r cannot change, therefore must be initialized
  a1.f();        // ________________
  p = &a1;       // ________________
  p->f();        // (*p).f()________________
  q = &a1;       // ________________
  a2.f();        // ILLEGAL: a2 is NOT AN OBJECT! it's a FUNCTION_______
  q->f();        // ILLEGAL: q is a pointer ot const.  f is not const
}





