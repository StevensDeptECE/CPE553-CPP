#include "Rect.hh"
using namespace std;

Rect::Rect(float x, float y, float w, float h) 
: x(x), y(y), w(w), h(h) {
  cout << "Rect()\n";
}

void Rect::print(ostream& s) const {
  s << x << " " << y << " moveto " << 
    (x+w) << " " <<  y  << " lineto " <<
    (x+w) << " " << (y+h) << " lineto " << 
    x << " " << (y+h) << " lineto closepath stroke\n";
}