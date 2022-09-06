#include <iostream>
using namespace std;

int main() {
  int a = 2;
  const int b = 3;

  int  *p = &a;
  *p = 5; // *p is an alias for a, a just got set to 5
  cout << &a << '\n';
  int* q = &a;
  cout << *q << '\n';
  *q = 6;
  q = (int*)&b;
  *q = 19;
  cout << b << '\n';
  cout << &b << '\n';
  cout << q << '\n';
  q = (int*)0x7ffe3ff22d84L;
  *q = 55;
  cout << *q << '\n';
  
  }