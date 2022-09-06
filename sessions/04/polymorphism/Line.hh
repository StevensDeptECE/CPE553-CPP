#include<iostream>
#include "Shape.hh"
#include <cmath>

class Line : public Shape {
private:
	double x2, y2;
public:
	Line(double x1, double y1, double x2, double y2) : Shape(x1, y1) {}
	//double area() const = 0; //Every shape must have its own area/perimeter
	double perimeter() const override{ // Line has no perimeter
		return _distance(x,y, x2,y2);
  } 
  double area()  const override { // Line has no area
    return 0;
    }
  void print(std::ostream& s) const {
		s << "Perimeter: " << perimeter() << ", Area: " << area();
	}
};