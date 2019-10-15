#include <iostream>
using namespace std;

int main() {
  int a = -1; // usually signed not guaranteed
	cout << sizeof(int) << '\n';
	unsigned int b = 2U;
	signed int c = -2;
	long int d = 123456789012345678L;
	cout << sizeof(d) << '\n';
	long long int e = 123456789012345678LL;
	cout << sizeof(e) << '\n';
  short int f = 123;
	char g = 1; // char is one atomic memory unit (most computers, byte)
	cout << sizeof(char) << '\n';

	int8_t x1; // signed
	uint8_t y1; // unsigned

	int16_t x2; // signed
	uint16_t y2; // unsigned

	int32_t x3; // signed
	uint32_t y3; // unsigned

	int64_t x4; // signed
	uint64_t y4; // unsigned
}
