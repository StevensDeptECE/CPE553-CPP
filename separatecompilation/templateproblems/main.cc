#include "Complex.hh"
#include <string>
#include <iostream>
using namespace std;

int main() {
    Complex<double> a(1.5, 2.1);
    Complex<double> b(1.5, 2.1);
    Complex<double> c = a + b;
    cout << c << endl;
    c.big(10);

    Complex<float> d(1.5f, 2.3f);
    Complex<float> e(-1.25f, 9.1f);
    Complex<float> f = d + e;
    cout << f << endl;
    f.big(10);
    //ILLEGAL, cannot mix: Complex<double> c2 = a + e;

#if 0
    Complex<string> g("hello", "there");
    Complex<string> h("x", "y");
    Complex<string> i = g + h;
    cout << i << endl;
    i.big(10);
#endif 
}