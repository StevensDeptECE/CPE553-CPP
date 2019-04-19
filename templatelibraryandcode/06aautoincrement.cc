#include <iostream>
using namespace std;
int main() {
	int a = 2;
	cout << a++; // prints out 2
	cout << a; // this time a = 3!


	int c = 3, d = 4;

	int e = c++ + ++d;
	cout << e;

	cout << '\n';
	cout << c++ << c++ << '\n';
	cout << ++c << ++c << '\n';
}
