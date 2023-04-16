#include <vector>
#include <iostream>
using namespace std;
#include "Shape.hh"
#include "Circle.hh"
#include "Rect.hh"

int main() {
  vector<Shape*> shapes;
  shapes.push_back(new Circle(100,200,50));   //x,y,r   "100 200 50 0 360 arc stroke\n"
  shapes.push_back(new Rect(300,400,100,50)); //x,y,w,h "300 400 moveto x+w y lineto  x+w,y+h lineto x y+h lineto closepath stroke"

  for (auto s : shapes) {
    s->print(cout);
  }

}