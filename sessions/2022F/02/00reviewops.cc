#include  <iostream>
using namespace std;

int main() {
	int a = 1000 * 1000; // on Arduino,  -32768 .. 32767
	int b = 50000 * 50000;
	int c = 15 / 2 * 2;
	int d = 15 * 2 / 2;
	int e = 3 % 3 * 3;
	int f = 2 + 3 * 4;
	int g = 15 / (2 * 2);
	uint16_t h = 65534 + 3;  // 16 bits have 2^16 = 65536  0..65535
	cout << "a=" << a << '\n';
	cout << "b=" << b << '\n';
	cout << "c=" << c << '\n';
	cout << "d=" << d << '\n';
	cout << "e=" << e << '\n';
	cout << "f=" << f << '\n';
	cout << "g=" << g << '\n';
	cout << "h=" << h << '\n';
	// -32768..32767
	// 0.. 65535
	a += 3; // a = a + 3
	b -= 2; // b = b - 2
	c *= 3; // c = c * 3
	d /= 3; // d = d / 3
	c %= 7; // c = c % 7
}
/*
  0    000   0
	1    001   1
	2    010   2
	3    011   3
	4    100  -4
	5    101  -3
	6    110  -2
	7    111  -1   
         1
     -----
      1000
 */
