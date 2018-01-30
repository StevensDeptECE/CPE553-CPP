#include <iostream>
using namespace std;

void hello() {
	cout << "hello";
}

void test(int a) {
	for (int i = 0; i < a; i++)
		cout << "a";
}

// f(x) = x*x
double f(double x) {
	return x*x;
}

inline double g(double x) {
	return x*x;
}


int main() {
	5;
	5+2;
	hello;
	hello();
	hello();
	test(5);
	cout << f(2.0) << "\n";
	cout << g(2.0) << "\n";
}
