#include <iostream>
using namespace std;

void f() {
  uint32_t myVar; // always initialize your variables! This is an error
  cout << myVar << '\n';
  uint32_t myVar2;
  cout << myVar2 << '\n';
}

int main() {
  /*
  
       unsigned   signed
  000   0         0
  001   1         1
  010   2         2
  011   3         3
  100   4         -4
  101   5         -3
  110   6         -2
  111   7         -1

   111+
   001
  1000
  */
//  int x = 3000000000;
  short int x = 32767;
  cout<<x << '\n';
  x = x + 1;
  cout<<x << '\n';
  f();
  
}