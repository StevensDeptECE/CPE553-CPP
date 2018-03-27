class Vector3d {
private:
	double x,y,z;

public:
	Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}
};

Vector3d v1(1,2,3);
Vector3d v2 = v1;
