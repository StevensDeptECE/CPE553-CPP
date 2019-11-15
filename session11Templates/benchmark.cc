#include <iostream>
#include <time.h>
using namespace std;

uint32_t fillMemory(int* p, int n) {
	for (int i = 0; i < n; i++)
		p[i] = 0;
	return 0;
}

uint32_t fillReverse(int* p, int n) {
	int* q = p + n-1;
	for (int i = 0; i < n; i++)
		*q-- = 0;
	return 0;
}

uint32_t fillInterleaved(int* p, int n) {
	for (int j = 0; j < 16; j++)
		for (int i = j; i < n; i+= 16)
		p[i] = 0;
	return 0;
}

uint32_t read(int* p, int n) {
	uint32_t sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
  return sum;
}

typedef uint32_t (*MemWithSizeFunc)(int*, int);

void benchmark(const char msg[],
							 uint32_t (*f)(int*, int);, int* p, int n) {
void benchmark(const char msg[], MemWithSizeFunc f, int* p, int n) {
	clock_t t0 = clock();
	for (int trials = 0; trials < 10; trials++)
		uint32_t size = f(p, n);
	clock_t t1 = clock();
		
	cout << msg << "\t" << (t1-t0) / 10 << '\n';

}
int main() {
	const int n = 10000000;
	int* p = new int[n];
  benchmark("read", read, p, n);
	benchmark("fillMemory", fillMemory, p, n);
	benchmark("fillReverse", fillReverse, p, n);
	benchmark("fillInterleaved", fillInterleaved, p, n);
}
