#include <iostream>
using namespace std;


int main() {
	constexpr int SIZE = 10;
	int x[SIZE] = {5, 6, 1};

	for (int i = 0; i < SIZE; i++)
		cout << x[i] << ' ';
	cout << '\n';

	for (int* p = &x[0]; p < x + 10; p++ ) // p++ adds sizeof(int) bytes
		cout << *p << ' ';
	cout << '\n';

	for (int* p = &x[0]; p <= x + 9; p++ )
		cout << *p << ' ';
	cout << '\n';

	for (int *p = x ; p < x + 10; p++)
		cout << *p << ' ';
	cout << '\n';

	uint64_t y[5] = {9, 1, 4, 2};
	for (uint64_t* p = y; p < y+5; p++) // p = p + sizeof(uint64_t) which is 8
		cout << *p << ' ';
	cout << '\n';
		
}
