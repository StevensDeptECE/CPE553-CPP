int main() {
	// a file with this name must exist in the current directory
	ifstream f("vec3d.dat");
	vec_3d v1,v2;
	f >> v1 >> v2; // read in two vectors from the file
	const vec_3d v3 = v1 + v2;
	const vec_3d v4 = v2 * 2; // scalar multiply
	const double d1 = dist(v3, v4); // compute using a friend function
	const double d2 = v3.dist(v4); // compute using a method
	const double d3 = vec_3d::dist(v3, v4); // compute using a static function

	double mag = m = v1.mag();
	double magsq = m = v1.magsq();
	cout << "v3=" << v3 << '\n';
	cout << "v4=" << v3 << '\n';
	cout << "d1=" << d1 << '\n';
	cout << "d2=" << d2 << '\n';
	cout << "d3=" << d3 << '\n';
	 
}
