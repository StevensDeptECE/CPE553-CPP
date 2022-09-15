int main() {
	const Vec3d a(1.0,0.5,0.0);
	const Vec3d b(1.0,0.5,0.0);
	cout << a << '\n';
	const Vec3d c = a + b;
	const Vec3d d = c * 1.5;
	const Vec3d d2 = 1.5 * c;
	const Vec3d e = -a;
	cout << c << '\n';
	cout << d << '\n';
	cout << d2 << '\n';
	cout << e << '\n';
	double m = a.mag(); // abs value, magnitude..
	cout << m << '\n';
	double msq = a.magsq();
}
