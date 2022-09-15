#include <iostream>

int main() {
	int a = 2;
	int* p = &a; // p is pointer to int, initialized to the location of a
	*p = 3; // changes a
	cout << *p++; // print out the location of a, now p is pointing to next
	//location.  referencing this location would be an error
	// (undefined, could even crash theoretically if it goes out of bounds)

	int& r = a; // r is a reference, permanently refers to a

	const int b = 3; // b may not change
	const int* q = &b; // q is a readonly pointer
	cout << *q;
	q = &a; // now q points to a.  That's ok.  We promise not to change *q
	// that does not mean that b doesn't change, just that we can't change it.

}

	
	
