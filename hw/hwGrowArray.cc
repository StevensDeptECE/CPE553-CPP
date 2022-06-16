#include "GrowArray.hh"

int main() {
	GrowArray a(5); // preallocate enough space for 5 integers
	for (int i = 0; i < 10; i++) // this loop will have to grow after the 5th time
		a.addEnd(i);
	
	for (int i = 10; i < 20; i++) // this should grow once
		a.addEnd(i);

	cout << a;
}
