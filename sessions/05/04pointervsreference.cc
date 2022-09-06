#include <iostream>
using namespace std;
void f(int x) { cout << x; x = 0; }
void g(int& x) { cout << x; x = 0; }
void h(int* x) { cout << *x; *x = 1; }

int main() {
  int a = 2;
  const int b = 3;
  int& r = a;
  cout << &r << '\t' << &a << '\n';
  cout << sizeof(r) << '\t' << sizeof(a) << '\t';
	r = b; // a is now 3
	
  //  int& r2 = b; //error, r2 is not const
  //  r2 = 4;
	
  const int& r2 = b;
  cout << r2 << '\n';

  int* p = &a; // p points to a
  cout << p << '\t' << &a << '\n';
  cout << &p << '\n';
  f(a);
  cout << a << '\n'; // a is still the same
  g(a); // a is now ZERO
  cout << a << '\n'; // a is NOW 1
  h(&a); // passing address of a, hmmm a could change....
  //  h(nullptr); // change this, you die.
}


  
