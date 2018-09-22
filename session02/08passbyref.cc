#include <iostream>
using namespace std;

void f(int x) {
  cout << x;
	x += 5;
}

void g(int& x) {
  cout << x;
	x += 5;
}

int main() {
	int a = 3;
	f(a); // 3
	f(a); // 3 parameters are passed by VALUE (copy)
	f(4); // notice, 4 does not change!!!
	g(a); // 3 but now a = 8
	g(a); // 8 now a = 13
	g(12);

	const int & r = 4;
	int b = 4;
	b = 5;
	5 = b;
}
