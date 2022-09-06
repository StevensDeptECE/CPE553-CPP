int main() {
	int a = 2;
	const int b = 3;
	int* p = &a;
	*p = 99;
	print(b); // pass by reference and make it work

	const Fraction f1(1,2);
	cout << f1; // print out 1/2. pass by reference for speed

	p = new int[10];


	delete [] p;
	p = new int[5];


	delete p;

	p = new int(3);
	delete [] p;

	p = new int[10];
	delete []p;
	delete []p;
	p = new int[10];

	int* x[10];
	for (int i = 0; i < 10; i++)
		x[i] = new int(22);

	// free it!
}
