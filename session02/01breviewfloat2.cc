 #include <iostream>
#include <iomanip>

using namespace std;
/*
    floating point approximates real numbers


*/
int main() {
    float f = 1.2345678f; // 32bits
    f=123.45678;
    f=6.022e+23;
    f=5.97e-11;
    double d = 1.23456789012345; // 64bits
    d = 1.234e+308;
    d = 1.234e-308;
    long double ld = 1.23456789012314567890L; // not standard
    //quad precision _float128

    // t = 70.0000

    cout << setprecision(8);

    for (float x = 0; x < 10; x += 0.1f)
      cout << x << ' ';
    cout << '\n';
    /*
        1/2 = 0.5
        1 /3 = .33333333333
        1/10 = 0.1

      .101011101010101010101010
    seeeeeeeemmmmmmmmmmmmmmmmmmmmmm
    0000000000000000000000000000001


    010

    011

    100
0111111100000000000000000000001
0011111100000000000000000000001

    */
   int i;
   double x;
   for (x = 0, i = 0; i < 100; i++, x += 0.1)
     cout << x << ' ';

   for (int j = 0; j < 100; j++)
     cout << 0.1*j << ' ';
/*
    a + b == b + a
    a + b + c == a + (b+c) NOT TRUE in floating point

    1.23
     .568
     .0496
===========
    1.79
     .0496
    1.83

     .568
     .0496
     =====
     .617
    1.23
    1.84
*/



}