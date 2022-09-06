#include <cstdio>
#include <cstdarg>
using namespace std;


void myprint(int a, ...) {
	// address of a = &a + 1
	va_list args;
	va_start(args, a); // point to the ... (64-bit aligned?)
	int v;
	do {
		v = va_arg(args, int);
		printf("%d ", v);
	} while (v > 0);
	va_end(args);
}

int main () {
	printf("%d\n", 3);
	printf("%d %d\n", 3, 4);
	printf("%d %lf %d\n", 3, 3.2, 4);
	printf("%lf %lf %d\n", 3, 3.2, 4);
	myprint(2, 0);
	myprint(2, 3, 4, 0);
  myprint(2, 3, 4, 9, 9, 9, 8, -1.223242353265327e+99, 0);
	return 0;
}
