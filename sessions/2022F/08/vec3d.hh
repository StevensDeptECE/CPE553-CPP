#ifndef VEC3D_HH_
#define VEC3D_HH_

class vec3d {
private:
  double x,y,z;
public:
  vec3d(double x = 0, double y = 0, double z = 0);
  friend vec3d operator +(vec3d a, vec3d b);
  friend vec3d operator -(vec3d a);

 vec3d operator -(vec3d b) const;
 const vec3d& operator +() const;

 double abs() const;
 friend double abs(vec3d v);

};
#endif