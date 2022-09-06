#include <iostream>
using namespace std;

template<typename T>
void sort(T* const x, uint32_t n) {
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1; i++)
			if (x[i] > x[i+1]) {
				int temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
}

template<typename T>
void print(const T x[], uint32_t n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << "\n\n";
}

int main() {
	int x[] = {4, 3, 2, 1};
	const uint32_t n = sizeof(x)/sizeof(int);
	sort(x, n);
	print(x, n);
	float y[] = {4.2f, 2.1f, 3.6f, 5.2f, 2.8f};
	sort(y, sizeof(y)/sizeof(float));
	print(y, sizeof(y)/sizeof(float));
}
