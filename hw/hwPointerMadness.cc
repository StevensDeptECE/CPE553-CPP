#include <iostream>
using namespace std;
/**
	 This is a self-check on pointer operations.  See if you can figure out what the code does.
	 You can always run the code to find out.

	 @author: Dov Kruger
 */
void print(const int* p, int size) {
	for ( ; size > 0; size--, p++)
		cout << *p << ' ';
	cout << '\n';
}

void difficulty1() {
	int x[] = {5, 4, 9, 2};
	int* p = &x[1];
	*p++ = 11;
	*p++ = 2;
	--*p;
	(*p)--;
	print(x, sizeof(x)/sizeof(int));
}

void difficulty2() {
	int x[8] = {8, 8, 4, 3};
	int* p = &x[4];
	for (int i = 3; i > 0; i--)
		*p++ = 11;
	for (int i = 4; i > 0; i--)
		--*p;
	for (int i = 2; i > 0; i--, p++)
		*p++ = 2;
	print(x, sizeof(x)/sizeof(int));
}

void difficulty3() {
	int x[8] = {5, 4, 9, 2};
	int* p = &x[4];
	p += 3;
	*p-- = p[-1];
	for (int i = 3; i > 0; i--, p--)
		p[1] = p[-3];
	
	print(x, sizeof(x)/sizeof(int));
}


int main() {
	difficulty1();
	difficulty2();
	difficulty3();
}

