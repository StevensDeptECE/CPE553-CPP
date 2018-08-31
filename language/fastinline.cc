double f() {
	int sum = 0;
	for (int i = 1; i < 1000000; i++)
		sum += i;
	for (int i = 1; i < 1000000; i++)
		sum += 1/i;
	for (int i = 1; i < 1000000; i++)
		sum += 2/i;
	return sum + 0.5;
}



}



int h(int x, int y, int z) {
	return x + y + z;
}

void f(const char* msg) {
	cout << msg;
}

void g(const char* msg) {
	f(msg);
}

int main() {
	g("hello");
	cout << h(2,3,4); // 2+3+4 = 11
	double y = f();


	double z = f();

	double aa = f();
