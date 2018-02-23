#include <iostream>
using namespace std;

class A {
public:
  int a : 2;
  int b : 3;
  unsigned int c : 2;
};
int main() {
  A a1;
  cout << sizeof(a1) << '\n';
  a1.a = 0; // all possible values of 2-bit signed field
  a1.a = 1;
  a1.a = -1;
  a1.a = -2;

  a1.b = 0; // all possible values of 3-bit signed field
  a1.b = 1;
  a1.b = 2;
  a1.b = 3;
  a1.b = -4;
  a1.b = -3;
  a1.b = -2;
  a1.b = -1;
}
  
