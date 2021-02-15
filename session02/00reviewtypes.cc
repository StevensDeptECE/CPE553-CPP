#include <iostream>
using namespace std;

int main()  {

	int a;
	unsigned int b = 65535U;
	long c = 123455L; // >= int
	long long d = 123456789123435678LL;
	short int e = 123; //-32768..32767
	unsigned short int f; // 0..65535
	uint8_t u1;
	uint16_t u2;
	uint32_t u3;
	uint64_t u4;

	int8_t s1;
	int16_t s2;
	int32_t s3;
	int64_t s4;

	char e = 'x';
	char f = 65; // 'A'
	// something like this:	wchar_t w = '';

	float p;
	double q;  // 1.123456789012345e-308 ... -1.2412e+308
	long double r;


	bool s = true;
}
