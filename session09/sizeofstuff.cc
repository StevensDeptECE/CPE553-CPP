#include <iostream>
using namespace std;
void f(int y2[]) {
  cout << sizeof(y2) << '\n'; // 8 on a 64 bit computer
}
int main() {
	cout << sizeof(int) << '\n'; // 4 on my machine, not portable

	cout << sizeof(uint64_t) << '\n'; // 8 on almost everywhere
	uint32_t x;
	cout << sizeof(x) << '\n'; //4

	int y[10]; // 0 to 9
	cout << sizeof(y) << '\n'; // on my machine 4 * 10
	y[-10] = 55;
	y[13] = 92;

	int y2[] = {5, 4, 3};
	cout << sizeof(y2) << '\n'; // on my machine 4 * 3
	f(y2);
	f(y);
}
	
