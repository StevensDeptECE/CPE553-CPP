#include <iostream>
using namespace std;

int main() {
	int* p = new int;
	*p = 5;

	delete p;

	p = new int[1000];
	for (int i = 0; i < 1000; i++)
		p[i] = i;

	delete [] p; // undefined what happens if you forget []


	//	int*q ;
	//	*q = 5; // CRASH

	int a = 2;
	p = &a;

	delete p; // CRASH! must only delete pointers allocated with new

	int* q = new int[10];
	q++; 
	delete[] q; // CRASH you did not delete the pointer you were given

	// instead, try this to be safer:
	int* const q = new int[10];
	// not allowed to change where q points
	delete[] q;

	int* w = new int[10];
	delete [] w;
	delete [] w; // delete twice, and DIE!!!

	
	
}
