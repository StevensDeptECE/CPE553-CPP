int main() {
	const vec_3d v1(1.0, 2.5, 3.0);
	const vec_3d v2(2.0, 1.2, 2.5);
	const vec_3d v3 = v1 + v2;
	const vec_3d v4 = v2 * 2; // scalar multiply
	const double d1 = dist(v3, v4); // compute using a friend function
	const double d2 = v3.dist(v4); // compute using a method
	const double d3 = vec_3d::dist(v3, v4); // compute using a static function

	double mag = m = v1.mag();
	double magsq = m = v1.magsq();
}
