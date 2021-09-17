#include <iostream>
#include <cmath>
using namespace std;
void f(int x) {
	cout << x;
	x++;
}

void g(int& x) {
	cout << x;
	x++;
}

void h(int* p) {
  cout << p << ": " << *p << '\n';
}

int main() {
	int x = 4;
	f(x); //4
	f(x); // 4
	g(x); // 4
	g(x); // 5
	f(x); //6
	h(&x); // 6


	
}
