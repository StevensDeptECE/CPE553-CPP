#pragma once

#include <iostream>
#include "Shape.hh"
#include <cmath>
class Triangle: public Shape {
private:
	double x2, y2, x3, y3;

public : Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : Shape(x1, y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
	double area() const override{
		return sqrt(perimeter() *
					(perimeter() - _distance(x, y, x2, y2)) *
					(perimeter() - _distance(x2, y2, x3, y3)) *
					(perimeter() - _distance(x3, y3, x, y)));
	}

	double perimeter() const override{
        return _distance(x, y, x2, y2) + _distance(x, y, x3, y3) + _distance(x2, x2, y2, y3);
	}
    
    
	void print(std::ostream& s) const {
		s << "Perimeter: " << perimeter() << ", Area: " << area() << '\n';
	}
};
