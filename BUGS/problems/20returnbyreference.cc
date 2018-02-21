#include <iostream>
using namespace std;

//don't ignore the warnings! This program crashes at runtime.  What is wrong?
int& f(int x) {
	int y = x + 1;
	return y;
}

int& g(int x) {
	return x;
}

int& h(int& x) {
	return x;
}

int main() {
	int a = f(3);
	int b = 2;
	cout << a << g(b) << '\n';
	cout << h(b);
}
