#include <iostream>
#include <cstdint>
using namespace std;

int main() {
	uint32_t w = 2 + 2;
	int32_t x = 2 - 5;
	uint32_t x2 = 2 - 5;
	int32_t y = 3 * 4;
	int32_t z = 2 / 3;
	int32_t a = 2 % 3; // 2 MOD 3
	cout << w << ' ' << x << ' ' << x2 << ' ' << y << ' ' << z << ' ' << a << '\n';  //endl
	cout << 5 % 3 << 6 % 3 << 7 % 3 << 8 % 3 << '\n';  // % n  --> 0 to n-1
}
