#include <iostream>
using namespace std;

//don't ignore the warnings! This program crashes at runtime.  What is wrong?
int f(int* x) {
        x = x + 1;
	return x;
}

int& g(int x) {
	return 2*x;
}

int& h(int& x) {
	return x;
}

int main() {
	int a = 3;
	cout << f(&a); // this function should add 1 to a
	int b = 2;
	cout << a << '\n';
	cout << g(b) << '\n'; // return 2*b
	cout << h(&b);
}
