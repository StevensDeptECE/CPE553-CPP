void polarToRect(double r, double theta, double& x, double& y) {
  x = r * cos(theta);
	y = r * sin(theta);
}

void polarToRect(double r, double theta, double* x, double* y) {
  *x = r * cos(theta);
	*y = r * sin(theta);
}

void converttopolar() {
	double r = 2.5, theta = 1.59;
	double x,y;
	polarToRect(r, theta, &x, &y); // call c-style function

	polarToRect(r, theta, x, y); // call c++ style function (note you cannot tell that x,y are changed from the call)

}

int main() {
	int a = 2;
	int& r = a; // r is a reference to a
	cout  << sizeof(a) << '\n';
	cout  << sizeof(r) << '\n';
	cout << &a;
	cout << &r;
	r = 5;

