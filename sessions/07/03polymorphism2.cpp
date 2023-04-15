#include <iostream>
using namespace std;

class A {
  int x;
};
// sizeof(A) = 4

class B {
    public:
    void f() {}
}
//sizeof(B) = still 1 byte!

class C {
public:
   virtual void f() {}
}; // every object of this type adds a pointer to the VFT + 8 bytes

class D: public C {
public:
 void f() override {
    cout << "whatever";
 }
};

int main() {
  C c1;
  c1.f();
  D d1;
  d1.f(); // "whatever"

  C* p;
  p = &c1;
  p->f(); // what gets called?
  p = &d1;
  p->f(); // 





}