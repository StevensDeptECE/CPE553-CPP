#include <iostream>
using namespace std;

#if 0
// old c code....
bool g() {
  if (f() == false) {
    return false;
  }

}
bool f() {
  if (bad...)
    return false;
}
#endif

// an exception class
class DivByZero {
  
};


class Fraction {
private:
  int num, den;
public:
  Fraction(int n, int d) : num(n), den(d) {
    if (d == 0) {
      throw DivByZero();
    }
  }

};

void g() {
    Fraction d(1,0); // problem    Don't let us create a bad object
}

void f() {
  g();
}
int main() {
  try {
    Fraction a(1,2); // 1/2
    Fraction b(1,3); // 1/3
    //  Fraction c = a + b;

    f();
    Fraction e(1,2); // problem
    //  Fraction f = d + e;
  } catch (DivByZero e) {
    cout << "Div by zero\n";
  }

}
