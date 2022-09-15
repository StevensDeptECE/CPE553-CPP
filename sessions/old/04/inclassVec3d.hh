#include <iostream>
using namespace std;

class Vec3d {
private:
	double x,y,z;
public:
	Vec3d(double x, double y, double z) :
		x(x), y(y), z(z) {}
	Vec3d() :	x(0), y(0), z(0) {}
	double dot(const Vec3d& b) const  {     //a.dot(b)
		return x*b.x + y*b.y + z*b.z;
	}
  friend Vec3d operator +(const Vec3d& a, const Vec3d& b) {
		return Vec3d(a.x+b.x, a.y+b.y, a.z+b.z);
	}
  Vec3d operator -(const Vec3d& b) const {
		return Vec3d(this->x-b.x, this->y-b.y, this->z-b.z);
	}
  Vec3d operator -() const {
		return Vec3d(-x,-y,-z);
	}
  friend ostream& operator <<(ostream& s, const Vec3d& v) {
		return s << v.x << ',' << v.y << ',' << v.z;
	}
};

int main() {
	const Vec3d a(1.0, 2.5, 3.2);
	const Vec3d b(2.0, -1.5, 0.5);
	// dot product ax*bx + ay*by + az*bz
  Vec3d g; // (0,0,0)
	Vec3d h(); // not an object!  h is a function that return Vec3d

	double d = a.dot(b); // dot(a,b)   Vec3d::dot(a,b)
	Vec3d c = a + b; //friend
	Vec3d f = a - b; // method, member function
	Vec3d e = -a; // (-1,-2.5, -3.2)
	cout << e << '\n';
}
