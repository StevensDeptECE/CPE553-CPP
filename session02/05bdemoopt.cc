#include <iostream>
using namespace std;
uint64_t sum(uint64_t n) {
	uint64_t sum = 0;
	const uint64_t n = 10000000000;
	for (uint64_t i = 0; i < n; i++)
		sum = sum + i;
	return sum;
}

int main() {
  cout << sum(1000) << '\n';
	cout << sum(1000000000) << '\n';
}
