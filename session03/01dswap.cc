#include <iostream>

int main() {
	int a = 2, b = 3;

	int temp;

	temp = a;
	a = b;
	b = temp;

	a += b;
	b = a - b;
	a -= b;

}
