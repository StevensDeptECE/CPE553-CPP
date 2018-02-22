#include <iostream>
using namespace std;

void f(int& x) {
  x = 0;
}

int main() {
  int a; // order of variables in memory is NOT GUARANTEED
  char c;
  cout << &a << '\n'; // the address of a, where it lives in memory
  // normally, we don't care where a lives, and we do not get to choose
  
  int b = 2;
  char d;
  cout << &b << '\n'; // the address of a, where it lives in memory

  
  const int c;
  const int d = 54;
  f(b);
  f(d);
  // a pointer is declared in reverse
  // "what p points to is an int, therefore p is a pointer to int"
  int  *p;
  cout << *p << '\n'; // probably crash, looking at random memory location
  *p = 124;
  int  *q = &a; // spaces make no difference.  q is pointing to a
  //int *a,b; // don't do this: a is a pointer to int, b is int
  double x[10];
  cout << x << "\n"; // the name of an array is a pointer to the start
  double* dp = &x[0]; // point to the location of the first element
  double* dp2 = x; // point to the location of the first element
  dp++; // advance to the next element (8 bytes at a time)
  cout << *dp << '\n'; // what prints out????

  dp = x + 5; // pointer addition works in terms of types, not bytes
  *dp = 2.5; // x[5] = 2.5
  p = x; //????? Types don't match.  But you can do this
  // if you try hard enough, and it is BAD
}
