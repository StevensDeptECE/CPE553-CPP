#ifndef SHAPE_HH
#define SHAPE_HH

#include <iostream>

class Shape {
public:
  virtual void print(std::ostream& s) const = 0;
};
#endif