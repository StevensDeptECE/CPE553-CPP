#include <iostream>
using namespace std;

int main() {
	int a = 1;
	const int b = 2;
	int* p = &a;
	cout << p << '\n';
	cout << *p << '\n';
	p = (int*)a; // this is dangerous.  Do you understand why?
	cout << p << '\n';
	cout << *p << '\n';
}
