#include <iostream>
using namespace std;
void g(int x, int y) {
	if (y == 0) {
		throw 5;
	}
}
void f() {
	g(3,0);
}

void h() {
	throw "abc";
}
int main() {
	try {
		f();
	} catch (int e) {
		cout << "Error: " << e;
	}
	try {
		g();
	} catch (const char* s) {
		cout << s << '\n';
	}
}


