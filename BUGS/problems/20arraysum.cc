#include <iostream>
using namespace std;

int main() {
	int x[] = {5, 4, 3, 2, 1};
	int j=19;
	int sum = 0;
	for (int i = 0; i <= 5; i++)
		sum += x[i];
	cout << sum << '\n';
}
