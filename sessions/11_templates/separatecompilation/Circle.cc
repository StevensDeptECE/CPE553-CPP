#include "Circle.hh"
using namespace std;

Circle::Circle(float x, float y, float r) 
: x(x), y(y), r(r) {
  cout << "Circle()\n";
}

void Circle::print(ostream& s) const {
  s << x << " " << y << " " << r << " 0 360 arc stroke\n";
}