#include <iostream>
using namespace std;
// intent: add all the numbers from 0.0 to 1000000.0 stepping 0.1 so 0.0 + 0.1 + 0.2 + ... + 999999.9 + 1000000.0
int main() {
	float sum = 0;
	for (float x = 0; x < 1000000; x += 0.1)
		sum += x;
	cout << sum << '\n';
	// is the answer right?  What should it be?
}
