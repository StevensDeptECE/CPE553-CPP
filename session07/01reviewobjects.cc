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
  const A* q;    // ________________
  A* const r;    // ILLEGAL: r cannot change, therefore must be initialized
  a1.f();        // ________________
  p = &a1;       // ________________
  p->f();        // ________________
  q = &a1;       // ________________
  a2.f();        // ________________
  q->f();        // ILLEGAL: q is a pointer ot const.  f is not const
}





