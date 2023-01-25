#include <iostream>
#include <numbers>
using namespace std;

// Shape is an ABSTRACT concept. I have no intention to make a shape
class Shape {
protected:
  double x, y; // location of the center of the shape
public:
  Shape(double x, double y) : x(x), y(y) {}
  virtual double area() const = 0; // pure virtual function
};


class Circle : public Shape {
private:
  double r;  
public:
  Circle(double x, double y, double r) : Shape(x,y), r(r) {}
  double area() const {
    return std::numbers::pi * r*r;
  }
  friend ostream& operator <<(ostream& os, const Circle& c) {
    return os << "x=" << c.x << " y=" << c.y << " r=" << c.r;
  }
};


class Rect : public Shape {
private:
  double w, h; // width and height
public:
  Rect(double x, double y, double w, double h) : Shape(x,y), w(w), h(h) { }
  double area() const {
    return w * h;
  }
  friend ostream& operator <<(ostream& s, const Rect& r) {
    return s << "x=" << r.x << " y=" << r.y << " w=" << r.w << " h=" << r.h;
  }
};

int main() {
    //Shape s; // illegal, because SHape is an ABSTRACT CLASS

    const Rect r1(10.0, 15.0, 3.0,4.0); // x=10,y=15 w=3, h=4
    cout << r1.area() << '\n'; // internally: call a function _WEIRD_MANGLED_area(&r1)
    Circle c1(50.2, 62.5, 4.0); // circle with radius 4.0
    cout << c1.area() << '\n';
    Shape* shapes[3] = { &r1, &c1, new Circle(200, 100, 15.5)};

    for (int i = 0; i < sizeof(shapes)/sizeof(Shape*); i++)
      cout << (*shapes[i]).area();

    for (int i = 0; i < sizeof(shapes)/sizeof(Shape*); i++)
      cout << shapes[i]->area();

    for (auto s : shapes) {
        cout << s->area();
    }

//    const int size = 3;
//    Circle circles[size] = { Circle(2,5,3.5), Circle(17,4, 28.2), {200, 100, 52.5} };
}