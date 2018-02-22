#include <iostream>
using namespace std;

// sum the numbers from 1 to n
int sum(int n) {
	int s = 0; // variables declared in functions that are not initialized have RANDOM GARBAGE!!!
	for (int i = 1; i <= n; i++) // up to AND INCLUDING n <=
		s += i; // not n!!!
	return s;
}

int main() {
	cout << sum(100) << '\n';
}
