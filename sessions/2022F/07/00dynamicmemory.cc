#include <iostream>

void f() {
	int a[20]; // variables declared on the stack lifetime = f
	//limited to 4MB by default
}
int main() {
	f();
	int* p = new int[10000000]; // allocate an array of any size on the heap
	
	delete [] p; // memory stays with the task until deleted

	Elephant* e = new Elephant[100];  // call Elephant::Elephant() 100 times

	delete [] e; // calls destructor 100 times
	
	uint64_t* q = new uint64_t[10000000];
	// any memory remaining at the end of the task is recovered when the task goes away
	// While the task is around this is called a memory leak. More on this later. 
}
