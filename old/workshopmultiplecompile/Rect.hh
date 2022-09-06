#pragma once

#include "Shape.hh"

class Rect : public Shape {
private:
    double w, h;

public:
    Rect(double x_, double y_, double w_, double h_) : Shape(x, y), w(w_), h(h_) {}
    double area() const override;
};