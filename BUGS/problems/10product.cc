#include <iostream>
using namespace std;

// sum the numbers from 1 to n
int prod(int n) {
	int p = 0;
	for (int i = 1; i <= n; i++)
		p *= i;
	return p;
}

int main() {
	cout << prod(5) << '\n';
	cout << prod(10) << '\n';
	cout << prod(20) << '\n';	
}
