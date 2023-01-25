#include <iostream>
#include <numbers>
using namespace std;


class Circle {
private:
  double x, y;
  double r;  
public:
  Circle(double x, double y, double r) : x(x), y(y), r(r) {}
  double area() const {
    return std::numbers::pi * r*r;
  }
  friend ostream& operator <<(ostream& os, const Circle& c) {
    return os << "x=" << c.x << " y=" << c.y << " r=" << c.r;
  }
  friend double area(Circle c);
};
// in C++ only friends have the right to touch your private parts
double area(Circle c) {
  return std::numbers::pi * c.r * c.r;
}


class Rect {
private:
  double x, y; // location of the center of the rectangle
  double w, h; // width and height
public:
  Rect(double x, double y, double w, double h) : y(y), w(w), h(h) {
    this->x = x;
  }
  double area() const {
    return w * h;
  }
  friend ostream& operator <<(ostream& s, const Rect& r) {
    return s << "x=" << r.x << " y=" << r.y << " w=" << r.w << " h=" << r.h;
  }
};

int main() {
    const Rect r1(10.0, 15.0, 3.0,4.0); // x=10,y=15 w=3, h=4
    const Rect r2(50,  152.5, 4.0,5.2);
    cout << r1.area() << '\n'; // internally: call a function _WEIRD_MANGLED_area(&r1)
    cout << r2.area() << '\n';
    cout << r1 << '\n';

    Circle c1(50.2, 62.5, 4.0); // circle with radius 4.0
    cout << c1.area() << '\n';
    cout << c1 << '\n';
    cout << area(c1) << '\n'; // regular function passing c1 as parameter
 

    const int size = 3;
    Circle circles[size] = { Circle(2,5,3.5), Circle(17,4, 28.2), {200, 100, 52.5} };
    for (int i = 0; i < size; i++)
      cout << circles[i].area() << '\n';

    for (auto c : circles) {
        cout << c.area() << '\n';
    }

    //    for (auto& c : circles) {
    //      c.r = 99;
    //    }

// don't make a copy, but promise not to change the list
    for (const auto& c : circles) {
        cout << c.area();
    }

    //for (auto s : circles)
    //  cout << s.area();   
}