#include <iostream>
using namespace std;
// FUNCTION f may be overloaded as long as each function has a different signature
void f() {
	cout << "hello";
}

inline double f(double x) {
 	return x*1.7;
}

int f(int x) {
	return x*x;
}

int main() {
	f();
	cout << f(2.5) << "\n";
	cout << f(2) << "\n";

	cout << f('a') << '\n';
	cout << f(2.5f) << '\n';
//error:	f("hello");
	
}




