#include <iostream>
#include <iomanip>
using namespace std;

int main() { // 
    float a = 1.2345678f;
    a = 12.345678f;
    a = 12345678.f;
    a = 1.234e+38;
    a = -1.234e-38;
    a= 70.0;
    //Kruger's rule: NEVER USE FLOAT


    double b = 1.23456789012345;
    b = 6.022e+23;
    b = 1.234e+308;
    b = 1.234e-308;
    long double c = 1.23456789012345678901234567890L;
    // IEEE754-2008


// 1/1 + 1/2 + 1/3 + 1/4 + ... + 1/100 = 5.18
    float sum = 0;
    for (float i = 1; i <= 100; i++)
//      sum = sum + 1.0 / i; // type promotion double(i)
     sum = sum + 1 / i; // float(1)
     //sum = sum + 1.0 / i;
     cout << setprecision(8);
    cout << sum;
/*
  1.23
  +.0891
  +.0149
  ======


  1.23
  +.0891
========
  1.31
 + .0149
 =====
  1.32
     11
  +.0891
  +.0149
========
   .1040
  1.23
  =====
  1 33

floating point:
   a + b = b + a // commutivity holds
   a + b + c != a + (b + c) Associativity does NOT hold.

*/





}