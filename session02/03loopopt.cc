#include <iostream>
using namespace std;

uint64_t sum(uint64_t a, uint64_t b) {
	uint64_t s = 0;
	for (uint64_t i = a; i <= b; i++)
		s += i;
	return s;
}

int main() {
	cout << sum(100000, 3000000000) << '\n';
}
