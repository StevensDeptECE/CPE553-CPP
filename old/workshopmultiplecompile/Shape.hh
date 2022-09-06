#pragma once

class Shape {
protected:
  double x,y;
public:
  Shape(double x, double y);
  virtual double area() const =0;
};