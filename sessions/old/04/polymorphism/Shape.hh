#pragma once

//#ifndef SHAPE_HH__
//#define SHAPE_HH__

#include <cmath>
#include <iostream>

class Shape {
protected:
	double x, y;
public:
	Shape(double x, double y): x(x), y(y) {}
	  virtual double area() const = 0; //Every shape must have its own area/perimeter
    virtual double perimeter()  const= 0; 
    void printShape(std::ostream& s) const {
        s << x << "," << y;
    }
    virtual void print(std::ostream& s) const = 0;
    friend std::ostream& operator <<(std::ostream& s, const Shape& sh) {
        sh.printShape(s);
        sh.print(s);
        return s;
    }   
};

inline double _distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

constexpr double pi = 3.14159265358979;
//#endif