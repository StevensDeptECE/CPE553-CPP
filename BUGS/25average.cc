#include <iostream>
using namespace std;

double mean(float x[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += x[i];
	return sum;
}

int main() {
	int maxVal = 0;
	int x[] = {80, 86, 85, 94, 73, 92, 81};
	cout << "mean=" << mean((float*)x, 7) << '\n';
}
