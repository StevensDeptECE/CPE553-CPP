void f() {
	int*t = new int[1000];

	// no delete, memory leak (no crash, but keep doing it and you will)
}

int main() {
	int* p;
	cout << *p; // looking at random pointer (CRASH!)
	delete p; // crash, never allocated (random)
	int a;
	int* q = &a;
	delete q; // crash, never allocated with new
  int*r = new int;
	delete r;
	delete r; // crash, deleted twice

	int*s = new int[10];
	delete s; // implementation defined what  happens (actually usually works)
	for (int i = 0; i < 10000000; i++)
		f();
}
