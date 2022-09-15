#include <iostream>
using namespace std;
#include "Fraction.hh"

int main() {
  Fraction a(1,2);
  Fraction b(1,3);
  Fraction c = a * b;
  cout << c << '\n';
}
