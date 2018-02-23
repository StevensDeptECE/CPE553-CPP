#include <iostream>
using namespace std;
/*
  Understanding the sizeof operator
*/

void f(const char s[]) {
  cout << sizeof(s) << '\n';
}

class A {}; // what is the size of an empty class?

class B { // what is the size of an object that contains an int?
private:
  int x;
};

class C { // what is the size of an object that contains 2 ints?
private:
  int x,y;
};

class D { // what is the size of an object containing mixed-sizes?
private:
  char a;
  int b;
  char c;
  double d;
  char e;
};

class E { // what is the size of an object containing mixed-sizes?
private:
  char a;
  char c;
  char e;
  int b;
  double d;
};

int main() {
  cout << sizeof(char) << '\n';
  cout << sizeof(short) << '\n';
  cout << sizeof(int) << '\n';
  cout << sizeof(long) << '\n';
  cout << sizeof(long long) << '\n';
  cout << sizeof(float) << '\n';
  cout << sizeof(double) << '\n';
  cout << sizeof(long double) << '\n';
  char s[20];
  cout << sizeof(s) << '\n';
  char* p = s;
  cout << sizeof(p) << '\n';
  cout << sizeof(*p) << '\n';
  f(s);
}
  
