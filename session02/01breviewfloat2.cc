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
}