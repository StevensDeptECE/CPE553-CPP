#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	int prod = 1;
	for (int i = 1; i <= n; i++) {
		prod = prod * i;
	}

	double recip = 0;
	for (int i = 1; i <= n; i++) {
		recip = recip + 1 / i;
	}
	cout << recip << '\n';
}
