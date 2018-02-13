int main() {
	// use friend operators
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d(); // d is a function that returns Vec3d
	const Vec3d e;

	const Vec3d f = a + e;
	const Vec3d g = b - d; // d is not an object, pick a different one
	double x = dot(f, g); // regular function
	double y = Vec3d::dot(f,g); // static function
	double z = f.dot(g); // method
	const Vec3d h = -b;

	double dist = f.mag(); // square root of sum of square
	double dist2 = f.magSq(); // sum of square
	double dist3 = f.dist(g); // sqrt or sum of square of diff
	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	cout << e << '\n';
	cout << f << '\n';
	cout << g << '\n';
	cout << h << '\n';
}

	

	
	
