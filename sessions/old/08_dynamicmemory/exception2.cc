#include <iostream>
using namespace std;
void g(int x, int y) {
	if (y == 0) {
		throw 5;
	}
	int z = x/y;
}
void f() {
	g(3,0);
}

void h() {
	throw "abc";
}
int main() {
#if 0
	//Do not use exceptions to bail out of loops! Use if statements!
	vector<int> list;
	for (int i = 0; i < 10; i++)
		list.push_back(i);
	for (int i = 0; i < 1000; i++)
		cout << list[i]
#endif
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


