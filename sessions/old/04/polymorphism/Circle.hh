#include "Shape.hh"

class Circle : public Shape {
private:
  double r;
public:

  Circle(double x, double y, double r) : Shape(x, y), r(r) {}

  double area() const override {
    return pi*r*r;
  } //Every shape must have its own area/perimeter

  double perimeter()  const override {
    return 2*pi*r;
  } 
  void print(std::ostream& s) const override {

  }
 };