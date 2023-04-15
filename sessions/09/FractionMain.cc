#include "Fraction.hh"
using namespace std;

int main() {
    Fraction f1(1,2);
    Fraction f2(1,3);
    Fraction f3 = f1 + f2;
    cout << f3;
}