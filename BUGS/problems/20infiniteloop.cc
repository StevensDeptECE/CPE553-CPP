#include <iostream>
using namespace std;
// intent: sum 1/n + 1/(n-1) + 1/(n-2) + ... + 1/1 where n = 100 million
int main() {
	float sum = 0;
	for (float x = 100000000; x > 0; x--)
		sum += 1.0 / x;
	cout << sum << '\n';
}
