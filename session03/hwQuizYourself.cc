#include <iostream>

using namespace std;

int f(int x) {
	x += 2;
	cout << 'x';
	return x*x;
}

int g(int& a) {
	a++;
	return 2;
}

int main() {
	int b = 2;
	int y = f(b);
	cout << y << '\n';
	y = f(b);
	cout << y << '\n';
	cout  << b << "\n";
	y = g(b);
	cout << y << '\n';
	cout  << b << "\n";
}
