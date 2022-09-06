#include <iostream>

int main() {
	int* p = new int[10]; // allocate 10 int (40 bytes)

	delete [] p;

	p = new int;

	delete p;

	p =(int*) malloc(1024);

	free(p);
	
	for (int i = 0; i < 10; i++)
		p[i] = i;
	// the block now contains the values 0 1 2 3 4 5 6 7 8 9

	// now, suppose you want to have one more value.  There is no room.
	// how to grow?

	//	p = new int[11]; // this would lose the old p
	int *old = p; // remember the old memory
	p = new int[11]; // allocate more
	for (int i = 0; i < 10; i++)
		p[i] = old[i]; // copy the old into the new
	p[10] = 77; // 0 1 2 3 4 5 6 7 8 9 77
	delete [] old;

	// now use p for a while


	// when you are done, delete p

	delete[] p; // in an object, this would be in the destructor
}
