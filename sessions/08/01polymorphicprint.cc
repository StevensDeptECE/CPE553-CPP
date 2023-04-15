#include <iostream>
#include <fstream>
using namespace std;
// pointer to Virtual Function Table (VFT) takes 8 bytes
class A {
public:
  friend ostream& operator <<(ostream& s, const A& a) {
    a.print(s);
    return s;
  }
  virtual void print(ostream& s) const = 0;
};

class B : public A {
public:
  void print(ostream& s) const override {
    s << "b";
  }
};

class C : public A {
public:
  void print(ostream& s) const override {
    s << "c";
  }
};

class D : public C {
    private:
    int x;
};
int main() {
    cout << sizeof(A) << '\n';
    cout << sizeof(B) << '\n';
    cout << sizeof(C) << '\n';
    cout << sizeof(D) << '\n';
  A* ap;
  B b1;
  C c1;
  cout << "individual polymorphic calls\n";

  ap = &b1;
  ap->print(cout);
  ap = &c1;
  ap->print(cout);
  A* array[] = {&b1, &c1};
  cout << "\n\ncall print on the array of pointers\n";
  for (auto a : array)
    a->print(cout);

  cout << "\n\ncall operator << on the array of pointers\n";
  for (auto a : array)
    cout << *a << '\n';

  ofstream f("test.dat");
  for (auto a : array)
    f << *a << '\n';
}
