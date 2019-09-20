int main() {
	Vec3d a(1.0, 2.5, 3.2);
	Vec3d b(2.0, -1.5, 0.5);
	// dot product ax*bx + ay*by + az*bz
  Vec3d g; // (0,0,0)
	Vec3d h(); // not an object!  h is a function that return Vec3d
	
	double d = a.dot(b); // dot(a,b)   Vec3d::dot(a,b)
	Vec3d c = a + b; //friend
	Vec3d f = a - b; // method, member function
	Vec3d e = -a; // (-1,-2.5, -3.2)
	cout << e << '\n';
}
