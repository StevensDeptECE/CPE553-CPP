#include <iostream>
#include <cstdint>
using namespace std;
int main() {
  int a = 2;
	int b = 3;
	uint32_t mylongvariablename = 4;
	// a < b
	// a <= b    a =< is NOT LEGAL!!!
	// a > b
	// a >= b
	// a == b
	// a != b  NOT equal
	//	if (2 == a)
	if (a == b) {
		cout << "equal\n";
	} else {
		cout << "NOT equal\n";
	}

	if (a == b) {
		cout << "equal\n";
		cout << "another thing\n";
	} else {
		cout << "NOT equal\n";
		cout << "yoho!\n";
	}
  if (a == b) 
		cout << "equal\n";
	else
		cout << "NOT equal\n";
	

	if (a % 2 == 0) {
		cout << a << " is even\n";
	}

	if (a % 3 == 0) {
		cout << a << " is a multiple of 3";
	}
/*
Golang and rust require {} so the () are not needed (simpler!)
	if a == b {

	}
	*/

}
