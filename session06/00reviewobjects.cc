#include <iostream>
using namespace std;


class A; // declaration
class A; // declaration
class A; // declaration
class A; // declaration
class A; // declaration
class A; // declaration
class A; // declaration

class A {}; // definition
extern int x; // declaration
int x; // definition: here it is
class B {
  int x;
  static int y; // declaration
};

int B::y = 1; // definition

int main() {
  cout << sizeof(A) << "\n";
  cout << sizeof(B) << "\n";

  int x;
  for (int i = 0; i < 5; i++) {

  }
}
