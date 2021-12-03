#include "Complex.hh"
#include <string>
#include <iostream>
using namespace std;

int main() {
    Complex a(1.5, 2.1);
    Complex b(1.5, 2.1);
    Complex c = a + b;
    cout << c << endl;
    c.big(10);
}