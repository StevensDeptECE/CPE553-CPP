int main() {
	int x[10] = {5, 4, 3, 2, 1};
	int* p = x;
	for (int i = 7; i > 0; i--)
		cout << *p++; // prints 5432100
	for (int i = 6; i > 0; i--)
		cout << *--p; // prints 0012345
}
