void f() {}

void veryLongFunction(int n) {
	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		...
		...
		..
	}

}
// rule: always inline small functions 1-2 lines
// always inline a function that is only called once

int main() {
	veryLongFunction(100);
	veryLongFunction(100);
	veryLongFunction(100);
	veryLongFunction(100);

}
