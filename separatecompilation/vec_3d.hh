class vec_3d {
public:
  double x,y,z;

	vec_3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z){}
  friend 	vec_3d operator +(const vec_3d& a, const vec_3d& b) {
		return vec_3d(a.x+b.x, a.y+b.y, a.z + b.z);
	}

  vec_3d operator -(const vec_3d& b) {
		return vec_3d(this->x-b.x, this->y-b.y, this->z - b.z);
	}
};


int main() {
	const vec_3d a(1.5, 2.2, 3.1);
	const vec_3d b(2.0, 3.1); // z = 0

	vec_3d c = a + b;
	vec_3d d = a - b;
}
