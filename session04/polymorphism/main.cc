#include <iostream>
#include "Circle.hh"
#include "Pentagon.hh"
#include "Ellipse.hh"
#include "Rect.hh"
#include "Line.hh"
#include "Triangle.hh"
using namespace std;


int main() {
    Circle c(10.0, 30.5, 50.6); // x,y,r
    Ellipse e(100, 100, 50, 30); // x,y,major axis, minor axis
    Rect r(10, 150, 30, 40); // x,y,w,h
    Line L1(200, 200, 300, 300); // no area, no perimeter
    Triangle t(100, 300, 200, 400, 150, 500); //3 vertices x,y
    Pentagon p(300, 400, 100); // centered at (300,400) with radius 100

    Shape* shapes[] = { &c, &e, &r, &p, &L1, &t};
    double sumArea= 0;
    double sumPerimeter = 0;
    for (int i = 0; i < sizeof(shapes)/sizeof(Shape*); i++) {
      sumArea += shapes[i]->area();
      sumPerimeter += shapes[i]->perimeter();
    }


    for (auto s : shapes) {
        s->print(cout);
    }

    for (auto s : shapes) {
        cout << *s;
    }

}