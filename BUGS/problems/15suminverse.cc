#include <iostream>
using namespace std;

// sum the numbers from 1 to n
float sumInverseSquares(int n) {
	float sum = 0;
	for (int i = n; i > 0; i--)
		sum += 1.0/(i*i);
	return sum;
}

int main() {
	cout << sumInverseSquares(1000000) << '\n';
}
