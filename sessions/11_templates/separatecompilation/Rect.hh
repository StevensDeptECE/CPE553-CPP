#pragma once
#include "Shape.hh"

class Rect : public Shape {
private:
  float x, y, w, h;
public:
  Rect(float x, float y, float w, float h);
  void print(std::ostream& s) const override;
};
