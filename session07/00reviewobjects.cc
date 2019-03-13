#include <iostream>
using namespace std;
class A { // definition: Creates class A
};

class A; // declaration: says that there is a class A
class A; // declaration: says that there is a class A
class A; // declaration: says that there is a class A
class A; // declaration: says that there is a class A
class A; // declaration: says that there is a class A

// function definition
void f() {
  cout << "hello";
}

// function prototype (declaration)
void f();
// function prototype (declaration)
void f();
// function prototype (declaration)
void f();
// function prototype (declaration)
void f();

class B {
public:
  B(int x) {}
};

int main() {
  int x; // declaration (also definition)
  A a1; // how big?  NOT ZERO   legal!!!
  A a2; // if sizeof(a1) == 0, then a1=a2???
  //fundamental principle: all objects must have unique identity
  B b1; // illegal: no matching constructor
  B b2(10);
  B b3(10.5); // automatically truncates to int
  B b4(2,3); // ILLEGAL: wrong number of parameters
}





