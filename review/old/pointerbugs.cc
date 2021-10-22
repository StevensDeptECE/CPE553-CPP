#include <iostream>

// illegal: cannot return reference to a constant
int& f1() {
  return 5;
}

// illegal: may not point at an object that goes away before the reference
int& f2() {
	int a = 2;
  return a;
}

//cannot point to value that is going away
int* g2() {
	int a = 2;
	return &a;
}

int main() {
	//	int& a = f1();
	//	a = 6;
	int& a = f2();
	a = 6;
}
