#include <iostream>
using namespace std;

int main() {
  int a = 1010101;
  double* p;
  //  p = &a; // this doesn't work.the compiler knows I am being stupid
  p = (double*)&a;
  cout << *p << '\n';
}
