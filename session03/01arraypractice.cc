#include <iostream>
using namespace std;

int main() {
	const int SIZE = 10;
	int a[SIZE]; // a[0] a[1] a[2] ... a[9]
	for (int i = 0; i < SIZE; i++)
		a[i] = i*2;
	// 0 2 4 6 8 10 12 14 16 18

	int b[10];
	for (int i = SIZE-1; i >= 0; i--)
		b[i] = a[SIZE-1-i];
	// b= 18 16 14 12 10 8 6 4 2 0

	for (int i = 0; i < SIZE; i++)
		cout << b[i] << ' ';
	cout << '\n';
}
