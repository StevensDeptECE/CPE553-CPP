int main() {
	double x[] = {1, 2, 3, 5.5, -1.2345, 99.28, 1.2345e3};
	double min, max, mean;
	stats(x, sizeof(x)/sizeof(double), min, max, mean);

	stats(x, sizeof(x)/sizeof(double), &min, &max, &mean);
	
}
