int main() {
	// build on the previous solar system homework.  The following is only an example
	SphericalBody b1("Earth", 5.972e24, Vec3d(0,0,0)); // earth mass and earth-relative location
	SphericalBody b2("moon", 7.347e22, Vec3d(3e8,0,0)); // moon mass and earth relative representative position

	cout << "Force on earth due to moon = " << b1.force(b2) << '\n';
	cout << "Force on moon due to earth = " << b2.force(b1) << '\n';
}
