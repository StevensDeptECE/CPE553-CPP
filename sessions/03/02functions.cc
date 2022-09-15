#include <iostream>
using namespace std;

void f() {
  cout << "hello";
}

void g(int a, int b) {
	cout << (a + b);
}

int main() {
	int x; // defines the variable x

	//	int x; // cannot define something twice

	//	f;
	//	f;
	//	f;
	//	5;
	//	5+2;
	f();
	g(2,3);	//cout << (5); // inlining

	g(3,5);
	int a, b;
	cin >> a >> b;
	g(a,b); // cout << (a+b)
	void f(); // DECLARES a function
	void f(); // DECLARES a function
	void f(); // DECLARES a function
}
