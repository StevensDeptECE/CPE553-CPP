#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;
void countPrimes(uint64_t* count, uint64_t a, uint64_t b)  {




	*count = 100;
}
int main() {
	uint64_t count1, count2;
	thread t1(countPrimes, &count1, 1, 500000000);
	thread t2(countPrimes, &count2, 500000001, 1000000000);
	t1.join();
	t2.join();
	cout << count1 << " " << count2 << "\n";
	//	cout << count1 + count2 << "\n";
}
