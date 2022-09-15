#include <iostream>
using namespace std;

int main() {
	int a = 2;
	int*p = &a; // p is pointing to a
	cout << a << '\n';
	cout << *p << '\n';
	*p = 3;
	cout << a << '\n';
	cout << "Address of a = " << p << '\n';
}
