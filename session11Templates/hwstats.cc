// can you write a generic mean() that takes different accuracy (float, double)
// but always computes the mean as double for accuracy?

int main() {
	float x[] = { 1.5, 2.5, 3.0, 5.0, 6.0};
	const int n = sizeof(x)/sizeof(float);
	cout << mean(x, n) << '\n';


	double x2[] = { 1.5, 2.5, 3.0, 5.0, 6.0};
	const int n2 = sizeof(x2)/sizeof(double);
	cout << mean(x2, n2) << '\n';

	//also possible: cout << variance(x2, n2);
}
