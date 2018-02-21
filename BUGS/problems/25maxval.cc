#include <iostream>
using namespace std;

int main() {
	int maxVal = 0;
	int x[] = {5, 4, 3, 2, 1};
	for (int i = 0; i < sizeof(x); i++) {
		if (x[i] > maxVal) {
			int maxVal = x[i];
		}
	}

	cout << "max value found =" << maxVal << '\n';
}
