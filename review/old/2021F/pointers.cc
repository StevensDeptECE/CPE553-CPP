#include <iostream>

int main() {
	int a[10] = {9,1,2,8,7};
	int*p = a+1;
	*p++ = 22;
	*++p = 11;
	--*p;
	*--p += 3;

	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << '\n';
}
