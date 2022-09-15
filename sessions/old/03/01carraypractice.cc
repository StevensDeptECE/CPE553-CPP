#include <iostream>
using namespace std;

int main() {
	const int SIZE = 10;
	int a[SIZE]; 
	for (int i = 0; i < SIZE; i++)
		a[i] = i*2;

	// reverse in place
	for (int i = 0; i < SIZE/2; i++)
		swap(a[i], a[SIZE-1-i]);

	// 0 2 4 6 8 10 12 14 16 18
	// 18 16 14 12 10 8 6 4 2 0
	for (int i = 0; i < SIZE; i++)
		cout << b[i] << ' ';
	cout << '\n';
}
