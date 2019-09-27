int main() {
	int a = 2;
	int x[10]; // x is uninitialized because it is declared in a function (auto variable)
	int* p = x; // or int*p = & x[0]

	int y[10] = {3}; // 3, 0, 0, 0, 0, 0, ...
	p = y;
	cout << *p << '\n'; // 3
	p++;
	*p = 19; // y[1] = 19
	++*p; // y[1] = 20
	int q = *p++; // q = 20 p = &y[2]
	(*p)++; // y[2] = 1
	q = (*p)++; // q = 1  y[2] = 2
	q = ++(*p); // q = 3  y[2] = 3
	q = *++p; // p = &y[3]  q = 0
	q = ++*p; // *p = 1 (y[3] = 1)   q = 1
