#include <iostream>
using namespace std;
void init(int x[], uint32_t len) {
  for (int i = 0; i < len; i++)
		x[i] = i;
}

void print(const int x[], uint32_t len) {
	for (int i = 0; i < len; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

// 9 1 2 3 4 5 6 7 8 0  -->  9 8 7 6 5 4 3 2 1 0
void reverse(int x[], uint32_t len) {
	for (int i = 0; i < len/2; i++) {
		int temp = x[i];
		x[i] = x[len-1-i];
		x[len-1-i] = temp;
	}
}

int main() {
	int a[10];
	init(a, sizeof(a)/sizeof(int));
	a[5] = 23;
	print(a, 10);
	const int SIZE = 5;
	int b[SIZE];
	init(b, SIZE);
	reverse(a, 10);
	print(a, 10);
}
