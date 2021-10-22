#include <iostream>
using namespace std;
class A {};

void objects() {
	cout << sizeof(A) << '\n'; // 
	A a1;   // a1 is an object (instance) of type A
	A a2(); // a2 is a function that returns A
	A::A(); // There is a function A inside class A (default constructor)
	// create a temporary object of type A and calls the constructor
}

int x; // global variable x (int, 4 bytes)
int main() {
	int a = 2;
	const int& b = a; // b is a reference to const integer (b cannot change a)
	// b can never refer to anything else
	int* c = &a; // c is a pointer to int (pointing at address of a)
	const int* d = &a; // d is a pointer to a constant int.  d cannot change a
	int* const e = &a; // e is a constant pointer (e must always point to a)
	*e = 5;
	float* f = (float*)&a; // f is a pointer to float pointing at a
	cout << f << '\n'; // what's wrong with this? reinterpreting int bits as float makes no sense!
	objects();
}
