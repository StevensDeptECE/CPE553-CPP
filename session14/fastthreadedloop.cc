#include <iostream>
//#include <omp.h>
using namespace std;

int main() {
	uint64_t sum = 0;
#pragma omp parallel for
	for (int i = 0; i < 1000000000; i++) {
		sum += i;
	}
	cout << sum << '\n';
}
