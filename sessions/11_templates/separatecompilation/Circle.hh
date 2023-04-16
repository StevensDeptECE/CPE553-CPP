#pragma once
#include "Shape.hh"

class Circle : public Shape {
private:
  float x,y,r;
public:
  Circle(float x, float y, float r);
  void print(std::ostream& s) const override;
};