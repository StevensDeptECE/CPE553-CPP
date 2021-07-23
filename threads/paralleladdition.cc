#include <iostream>
#include <thread>

using namespace std;

void add(int a[], int n, uint64_t* result) {
	uint64_t sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	*result = sum;
}

int main() {
	const int n = 2000000000;
	int* a = new int[n]; //Amdahl's law: the amount you can improve with parallel coding is limited by the sequential part
	for (int i = 0; i < n; i++)
		a[i] = i;

	const uint32_t numthreads = 4;
	uint64_t results[numthreads];
	uint32_t sizePerThread = n/numthreads;
	//	add(a, n, &results[0]);
	//#if 0
  thread t1(add, a, sizePerThread, &results[0]);
	thread t2(add, a+sizePerThread, sizePerThread, &results[1]);
	thread t3(add, a+sizePerThread*2, sizePerThread, &results[2]);
	thread t4(add, a+sizePerThread*3, sizePerThread, &results[3]);
  t1.join();
	t2.join();
	t3.join();
	t4.join();
	//#endif
	cout << results[0] << '\n';
	cout << results[1] << '\n';
	cout << results[2] << '\n';
	cout << results[3] << '\n';
	//Q: is this code faster than just running single threaded?
}

	
