#include <iostream>
using namespace std;

uint64_t sum(uint32_t a, uint32_t b) {
	uint64_t s = 0;
	for (uint32_t i = a; i <= b; i++)
		s += i;
	return s;
}

int main() {
	cout << sum(1, 1000000000) << '\n';
}
