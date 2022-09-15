/*
identify all the errors here

*/

int main() {
	int a = 3;
	int* p = a; // p is trying to point to memory address #3? not ok.

	int b; // this is on the stack
	p = &b;

	delete p;// you can only delete what you allocated with new

	p = new int[100];

	delete p; // needs matching []

	p = new int;
	free(p); // opposite of new is delete opposite of free is malloc

	p = new int[10]; // memory is allocated, leaks


	int* q; // what is q?

	delete [] q; // cannot delete random pointer

	q = nullptr;
	delete q; // this is ok
}
