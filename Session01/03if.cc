#include <iostream>
#include <cstdint>
using namespace std;
int main() {
  int a = 2;
	int b = 3;
	// a < b
	// a <= b  
	// a > b
	// a >= b
	// a == b
	if (a == b) {
		cout << "equal\n";
	} else {
		cout << "NOT equal\n";
	}

	if (a % 2 == 0) {
		cout << a << " is even\n";
	}

}
