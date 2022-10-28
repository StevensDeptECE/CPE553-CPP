#ifndef VEC3D_HH_
#define VEC3D_HH_

#include <cmath>
using namespace std;

class vec3d {
private:
  double x,y,z;
public:
  vec3d(double x, double y, double z) : x(x), y(y), z(z) {}
  friend vec3d operator +(vec3d a, vec3d b) {
    return vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
  }
  friend vec3d operator -(vec3d a) {
    return vec3d(-a.x, -a.y, -a.z);
  }

 vec3d operator -(vec3d b) const {
    return vec3d(x - b.x, y - b.y, z - b.z);
 }
 const vec3d& operator +() const {
    return *this;
 }

 double abs() const {
    return sqrt(x*x+y*y+z*z);
 }
 
 friend double abs(vec3d v) {
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
 }
};
#endif