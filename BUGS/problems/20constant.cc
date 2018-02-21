#include <iostream>
using namespace std;

int main() {
	const double pi = 3.14159265358979;
	const	void* p = &pi;
	int*q = (int*)p;
	*q = 3;
	cout << &pi << '\n';
	cout << q << '\n';
	
	cout << pi << '\n';
}
