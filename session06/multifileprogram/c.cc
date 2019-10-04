extern void g();
#include <iostream>
using namespace std;

extern int x;
int main() {
	g();
	g();
	cout << x;
  int x = 2;
	cout << x;
	cout << ::x; // prints the global one
	if (x < 3) {
		int x = 4;
		cout << x;
		cout << ::x;
	}
	cout << x;
	{
		int x = 5;
		// cannot refer to the outside x (shadowed the symbol)
	}
}
