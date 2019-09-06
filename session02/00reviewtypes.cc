#include <iostream>
using namespace std;

int main()  {
	int a;
	unsigned int b = 65535U;
	long c = 123455L; // >= int
	long long d = 123456789123435678LL;

	uint8_t x;
	uint16_t y;
	uint32_t z;
	uint64_t w;

	char e = 'x';
	char f = 65; // 'A'
	// something like this:	wchar_t w = '';

	float p;
	double q;  // 1.123456789012345e-308 ... -1.2412e+308
	long double r;


	bool s = true;
}
