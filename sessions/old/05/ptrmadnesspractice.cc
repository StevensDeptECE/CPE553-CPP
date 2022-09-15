#include <iostream>
using namespace std;

int main() {
  int x[10] = {19, 2, 4}; 
	int*p = x + 3;
	*p-- = 22; //  x[3]=22 p = &x[2]
	*p-- -= 2; // x[2] = 2 p = &x[1]
	for (int i = 0; i < 3; i++)
		*++p *= 2; // p=&x[2]  x[2] = 4  p=&x[3] x[3] = 44 p = &x[4] x[4] = 0
	for (int* p = x; p < x+10; p++)
		cout << *p << ' ';
	cout << '\n';
}
