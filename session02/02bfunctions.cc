#include <iostream>
using namespace std;
void f() {
	cout << "hello";
}

inline double f(double x) {
 	return x*x;
}

int f(int x) {
	return x*x;
}

int main() {
	f();
	cout << f(2.0) << "\n";
	cout << f(2) << "\n";
}
