#include <iostream>
using namespace std;

int main() {
	float sum = 0;
	for (float i = 1; i < 10; i++) {
		sum = sum + 1.0 / i;
		cout << sum << '\n';
	}
}
	
