#include <iostream>
#include <time.h>
using namespace std;

int division(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++)
		sum += 1/i;
	return sum;
}

int mult(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++)
		sum += i*i;
	return sum;
}

typedef int (*FuncIntParam)(int n);

void benchmark(FuncIntParam f, int n) {
	clock_t t0 = clock();
	f(n);
	clock_t t1 = clock();
	cout << (t1-t0) * 1e-9 << "elapsed\n";
}

int main() {
	const int n = 100000000;
	benchmark(division, n);
	benchmark(mult, n);
}

