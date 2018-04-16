#include <cstdlib>

int main() {
	int a = 2;
	int*p = &a;
	cout << a << '\n'; //2
	cout << *p << '\n';//2

	//ILLEGAL: Cannot delete what you did not allocate with new:	delete p;
	int*q = new int[1024]; // using new operator

	delete [] q;
	// cannot delete twice: CRASH!  delete [] q;

	int* r = malloc(1024*sizeof(int));
	//must match:	delete r;
	free(r);

}
