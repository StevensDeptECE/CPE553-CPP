#include <iostream>
using namespace std;

/*
  Read the notes on scope and lifetime.  This example contains
  every combination I can think of.

  Scope:    Where a symbol is visible within a program

  Lifetime: how long a variables lives. 
            When it is born, and when it dies.

  1. Global variables are visible  everywhere (scope) and live from the moment the program starts until after main is over.
  2. Extern refers to a global variable that must be defined somewhere else.
  3. A static variable inside a function is like a global, but has scope only within that function.
  4. A static variable outside a function is like a global, but is visible only within that file.
  5. A static variable within a class turns into an extern, requiring a global definition outside the class.

 */
const double PI = 3.1415926535897932;
const int x = 1; // mangled x_i ::x
extern int y;
void f();
namespace stevens {
  int x = 2; // stevens::x
}
class A {
  static int x; // --> extern int A::x;
};

int A::x = 3;

int main() {
  int x = 4;
  cout << x << '\n';
  cout << ::x << '\n';
  cout << stevens::x << '\n';
  cout << A::x << '\n';
  if (4 == x) { // why do you think the constant is first in this style?
    int x = 5;
    cout << x << '\n';
  }
  cout << x << '\n';
  cout << y << '\n';
  f(); // call the function in other.cc
  f(); // call the function in other.cc
}

// compile this program with g++ scopeandlifetime.cc other.cc
