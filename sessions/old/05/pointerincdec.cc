void case1(int* p) {
	for (int i = 0; i < 5; i++)
		*p++ = 99;
}

void case2(int* const p) {
	int*q = p;
	for (int i = 0; i < 5; i++)
		*q++ = 99;
}

void case3(const int* p) {
  int*q = p; // error, conversion of const int* to int*
	for (int i = 0; i < 5; i++)
		*q++ = 99;
	
}


int main() {
	int a[10] = {5, 4, 3};
	int b[10];
	const int*p = a;
	int* const r;
	//r++; // error!
	int*q = b;

	for (int i = 0; i < 10; i++)
		*q++ = *p++;

	int x;
	const int* r = &x;
	r++; // incorrect because we cannot count on order of memory
