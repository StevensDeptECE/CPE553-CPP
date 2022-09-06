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
double f(int x);

inline int g(int x) {
	return x*x;
}


int main() {
	5;     //does nothing...
	5+2;   //NOP
	hello; // NOP
	//	hello(); // calls hello
	//	hello();
	//	test(5);
	cout << f(2) << "\n";
	cout << g(2) << "\n";
}
