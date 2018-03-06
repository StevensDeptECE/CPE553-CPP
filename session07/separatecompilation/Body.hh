#pragma once

#include "Vec3d.hh"

class Body {
private:
  constexpr static double G = 6.67408E-11;
  double mass;
  Vec3d pos;  
public:

  // F = -G m1 m2 / (r12*r12)
  double force(const Body& b) const {
    // r12 = dist(pos, b.pos)
  }

  //  a = -G m / (r12*r12)
  double accel(const Body& b) const {
    return force() / mass;
  }

};
