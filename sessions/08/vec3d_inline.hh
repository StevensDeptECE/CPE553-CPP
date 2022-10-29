#pragma once

#include <cmath>
using namespace std;

class vec3d_inline {
private:
  double x,y,z;
public:
  vec3d_inline(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  friend vec3d_inline operator +(vec3d_inline a, vec3d_inline b) {
    return vec3d_inline(a.x + b.x, a.y + b.y, a.z + b.z);
  }
  friend vec3d_inline operator -(vec3d_inline a) {
    return vec3d_inline(-a.x, -a.y, -a.z);
  }

 vec3d_inline operator -(vec3d_inline b) const {
    return vec3d_inline(x - b.x, y - b.y, z - b.z);
 }
 const vec3d_inline& operator +() const {
    return *this;
 }

 double abs() const {
    return sqrt(x*x+y*y+z*z);
 }
 
 friend double abs(vec3d_inline v) {
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
 }
};
