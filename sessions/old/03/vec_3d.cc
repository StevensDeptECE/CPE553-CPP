/*
Make main work. You are NOT ALLOWED to change main

*/

int main() {
	vec_3d v1(1.5, 2.2, -3.1); // x=1.5 y=2.2 z-3.1
	vec_3d v2(-2.2, 1.2); // z = 0
	vec_3d v3(5.6); // y = z = 0
	vec_3d v4; // x = y = z = 0

	vec_3d v5 = v1 + v2;
	vec_3d v6 = v1 - v3;
	vec_3d v7 = -v2;// negation
	double d = dot(v1, v5); // dot product
	cout << v1 << '\n';
	cout << v2 << '\n';
	cout << v3 << '\n';
	cout << v4 << '\n';
	cout << v5 << '\n';
	cout << v6 << '\n';
	cout << v7 << '\n';\
	cin >> v1; // read in x, y, z from keyboard
	cout << v1.mag() << '\n'; // magnitude (abs)
	cout << v1.magsq() << '\n'; // magnitude squared  x*x+y*y+z*z
}
