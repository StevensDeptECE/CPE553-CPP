#include <iostream>

int optimize_int(int n) {
	int a = n;
	a = n+1;
	return a; // is the optimizer smart enough to do the right thing?
}

int optimize_array() {
	const int n = 10;
	int a[n] = {0};
	for (int i = 0; i < n; i++)
		a[i] = i;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum; // what can the optimizer do?
}

int optimize_array2() {
	const int n = 10;
	int a[n] = {0};
	for (int i = 0; i < n; i++)
		a[i] = i;
	int sum = 0;
	for (int i = 0; i < n; i += 2)
		sum += a[i];
	return sum; // what can the optimizer do?
}

int optimize_array3() {
	const int n = 10;
	int a[n] = {0};
	for (int i = 0; i < n; i++)
		a[i] = i;
	int sum = 0;
	for (int i = 1; i < n; i *= 2)
		sum += a[i];
	return sum; // what can the optimizer do?
}
#if 0
// uncomment and implement the function this calls
void call() {
  int a = prod(2, 3, 4); // a= product of the parameters 2*3*4
	cout << a << '\n';
}
#endif

int main() {
	const int w = 320, h = 200;
	int bitmap[h][w];
	
}
