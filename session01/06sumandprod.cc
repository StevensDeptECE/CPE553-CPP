#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i; // sum = sum + i     x = x * 2 --> x *= 2    y = y / 3  --> y/=3
	}
	cout << sum << '\n';

	int prod = 1;
	for (int i = 1; i <= 5; i++)
		prod = prod * i;
	cout << prod << '\n';

}
