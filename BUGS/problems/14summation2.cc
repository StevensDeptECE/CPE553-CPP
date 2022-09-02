#include <iostream>
using namespace std;

// sum the numbers from 1 to n
int sum(int n) {
	int s = 0;
	for (uint16_t i = 1; i <= n; i++)
		s += n;
	return s;
}

int main() {
	cout << sum(100000) << '\n';
	return 0;
}
