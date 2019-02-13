#include <iostream>

bool f(int x) {
	cout << "yo!";
	return x % 3 == 0;
}

int main() {
	int a = 2, b = 3;
	if (a < b || f(2)) // f(2) is never called because the if short-circuits
		cout << "hello\n"; // the first condition is true, and that is enough


	if (b < a && f(3)) // again, f(3) is never called because this cannot be
		cout << "no!\n"; // true, regardless. && shortcircuits if the first is false
	
}
