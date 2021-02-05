#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i; // sum = sum + i     //add i to sum
	}
	cout << sum << '\n';

	int prod = 1;
	for (int i = 1; i <= 5; i++)
		prod = prod * i; // prod *= i;
	cout << prod << '\n';

}
