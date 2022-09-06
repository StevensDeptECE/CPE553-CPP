#include <iostream>

int main() {
	float sum = 0;
	for (float i = 1; i <= 100000000.0f; i++)
		sum += i;
	return sum;
}
