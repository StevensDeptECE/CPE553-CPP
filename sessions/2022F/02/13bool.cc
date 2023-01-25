#include <iostream>

int main() {
	bool b = false;
	b = !b; // b is now true!
	cout << b << '\n';
	if (b) {
		cout << "true";
	} else
		cout << "false";
}
