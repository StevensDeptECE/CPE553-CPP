#include <iostream>
using namespace std;
int main() {
	int a = 2;
	cout << a++; // prints out 2
	cout << a; // this time a = 3!


	int c = 3, d = 4;

	int e = c++ + ++d; // e=8     c=4       d=5
	cout << e;

	//	int f = ++c + c++; // ?? NOT A CLUE, but don't do it!
	int f = c++ + c++; // NOT A GOOD IDEA 4+4 = 8  4+5 = 9  THE ANSWER IS UNDEFINED probably not 9901
	int g = ++c + ++c; // NOT A GOOD IDEA  DO NOT USE AUTOINCREMENT TWICE ON THE SAME VARIABLE, SAME STATEMENT.
	cout << '\n';
	cout << c++ << c++ << '\n';
	cout << ++c << ++c << '\n';
}
