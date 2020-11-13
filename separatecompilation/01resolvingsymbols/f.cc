#include <iostream>
using namespace std;

extern int x;
extern uint64_t pi;


void f() {
	cout << "hello x=" << x << '\n';
	pi = 4;
	cout << pi << '\n';
}
