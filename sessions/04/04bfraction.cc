#include <iostream>
using namespace std;

class fraction {
private:
  int num;
  int den;
public:
  fraction(int n = 0, int d = 1) {
    num = n;
    den = d;
  }

  // this points to the object
  void print() const {
    cout << this->num << "/" << den;
  }

  void g() const {
    cout << "yo!";
    num = 99;
  }

  void f() const {
    cout << "hello";
    g();
  }
};

int main() {
  const fraction a; //  0/1
  fraction b(1,2);  //   1/2
  a.print();
  cout << "\n\n";
  b.print();
  a.f();
  cout << "\n\n";

//  fraction c = a + b; // c = a.add(b);   c = add(a,b);

}