#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
	int a[] = {1, 3, 5};
	int b[10] = {2};
	int n;
	cin >> n;
	int c[n]; // int* const c = new int[n];
	for (int i = 0; i < n; i++)
		c[i] = rand();
	for (int*p = &c[n-1]; p >= c; p--)
		cout << *p << ' ';
	//	delete [] c;
}
