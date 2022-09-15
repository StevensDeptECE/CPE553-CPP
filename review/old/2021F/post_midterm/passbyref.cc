void stats(const double arr[], uint32_t n, double& mean, double& var) {
	double sum = 0;
	for (uint32_t i = 0; i < n; i++)
		sum += arr[i];
	mean = sum / n;
}

void stats(const double arr[], uint32_t n, double* mean, double* var) {
	double sum = 0;
	for (uint32_t i = 0; i < n; i++)
		sum += arr[i];
	*mean = sum / n;
	

}

int main() {
	double mean, variance;
	double x[] = {1, 2, 3, 4};

	stats(x, 4, mean, variance);    // variance = sum(square(x[i] - mean))/n
	stats(x, 4, &mean, &variance);    // variance = sum(square(x[i] - mean))/n
