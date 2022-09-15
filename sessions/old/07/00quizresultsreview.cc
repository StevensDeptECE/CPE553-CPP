int main() {
	int a = 9.0 / 10.0 * 3; // 2
	double b = 9/10*3; // 0.0
	int c = 2;
	int d = c++; // d =2 c = 3
	int e = --d; // e = 1 d = 1
	int* p = &a;
	++*p;
	cout << a << b << c << d << '\n'; // 3031

	int x[] = {4, 3, 2, 1};
	p = &x[0];
	int*q = &x[3];
	*p++ = *q--; //x[0] = 1
	for (p = &x[3]; p > x; p--)
		cout << *p << ' ';          // 1 2 3
	for (p = &x[3]; p >= x; p--)
		cout << *p << ' ';          // 1 2 3 1
}

int f(int x) {
	return ++x + 1;
}

int f(int& x) {
	return ++x + 1;
}

void q2() {
	int a = 5;
	int b = f(a); //
	int c = f(a);
	cout << a << b << c << '\n';  // 577\n
	cout << g(a) << g(a) << '\n';
}
