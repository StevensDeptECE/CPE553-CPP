#include <iostream>
using namespace std;

// compile this one with g++ -fpermissive to even have a chance of compiling and seeing it crash
// or just look at the compile-time error and understand the problem
int main() {
	int a = 5;
	int* p = a;
	cout << *p << '\n';
}
