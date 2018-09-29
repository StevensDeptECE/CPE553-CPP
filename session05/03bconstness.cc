#include <iostream>
using namespace std;

int main() {
	int a = 2;
	const int*p = &a; // p is a READONLY pointer
	cout << *p;
	a = 3; // a can change
	cout << *p;
}
