#include "vec3d.hh"
#include <cmath>
using namespace std;
vec3d::vec3d(double x, double y, double z): x(x), y(y), z(z){}

 vec3d operator +(vec3d a, vec3d b)
{
    return vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3d operator -(vec3d a) 
{
    return vec3d(-a.x, -a.y, -a.z);
}

vec3d vec3d::operator -(vec3d b) const
 {
    return vec3d(x - b.x, y - b.y, z - b.z);
 }

const vec3d& vec3d::operator +() const
 {
   return *this;
 }

 double vec3d::abs() const {
  return sqrt(x*x + y*y + z*z);
 }
 double abs(vec3d v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
 }
