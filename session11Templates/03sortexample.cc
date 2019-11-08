#include <iostream>
using namespace std;

void sort(int* const x, uint32_t n) {
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1; i++)
			if (x[i] > x[i+1]) {
				//			int temp = x[i];
				//			x[i] = x[i+1];
				//			x[i+1] = temp;
				
				//x[i] += x[i+1];
				//			x[i+1] = x[i] - x[i+1];
				//			x[i] = x[i] - x[i+1];
				
				//			x[i] ^= x[i+1];
				//			x[i+1] ^= x[i];
				//			x[i] ^= x[i+1];
				swap(x[i], x[i+1]);
			}
}

void sort(float* const x, uint32_t n) {
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1; i++)
			if (x[i] > x[i+1]) {
				swap(x[i], x[i+1]);
			}
}


int main() {
	int x[] = {4, 3, 2, 1};
	sort(x, sizeof(x)/sizeof(int));
	for (auto a : x) {
		cout << a << " ";
	}
	cout << '\n';
	float y[] = {4.2, 2.1, 3.6, 5.2, 2.8};
	sort(y, sizeof(y)/sizeof(float));
}
