#include <cstring>
#include <iostream>
#include <memory.h>

int main() {
	int* q = new int[1000];
	double *p;
	delete []     q; // LEGAL
	delete []q;      //ILLEGAL: delete each pointer only once
	int b;
	q = &b;
	q = new int;
	delete q;

	q = new int[10];
	delete q; // illegal

	q = new int[12];
	q[0] = 22;
	q = &q[5]; //    &*(q + 5)  == q + 5
	delete [] q; // ILLEGAL

	int* const p = &b;
	*p = 5;

	const int * r = &b;
	*r = 22; // ILLEGAL: r is a READONLY pointer, not allowed to write to the value

	const int x; // ERROR, how will we ever set x?

	int*const w; // how will we ever point w at anything?

	const int y = 99;
  int	* w = &y; // ILLEGAL: y cannot change
	*w = 55;
	
}
