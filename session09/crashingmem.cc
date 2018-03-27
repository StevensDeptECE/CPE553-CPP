int main() {
	int* p;
	delete p; // crash, never allocated (random)
	int a;
	int* q = &a;
	delete q; // crash, never allocated with new
  int*r = new int;
	delete r;
	delete r; // crash, deleted twice

	int*s = new int[10];
	delete s; // implementation defined what  happens (actually usually works)

	int*t = new int[10];

	// no delete, memory leak (no crash, but keep doing it and you will)
