#pragma once

#include "Shape.hh"

class Circle : public Shape {
private:
    double r;

public:
    Circle(double x_, double y_, double r_) : Shape(x_, y_), r(r_) {}
    double area() const override;
};
