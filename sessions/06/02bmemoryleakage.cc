void f(int n) {
	int* p = new int[n];
	p[0] = 99;
	///	p[1000] = 22;
	//	p[2000] = 33;
	p[n-1] = 102;

}

int main() {
	int a;
	int* p = new int[10];
	p = new int[10];

	delete[] p;
	for (int i = 0; i < 1000000; i++)
		f(100);
}
