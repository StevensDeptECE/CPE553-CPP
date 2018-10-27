#include "ReadDouble.hh"

int main() {
	const char buf[] = "0.0123456 -0.1234567  1.23456e-6 -8.765433 9.2131e+15";
	double val;
	uint32_t sigfigs;
	const char* p = buf;
	while (*p != '\0') {
		/*
			read the number starting at the character at p.
			store the number into the pointer in the second parameter (&val)
			store the number of significant figures (the number of digits following the
			first non-zero digit.  For example:
			0.0123456 has 6 significant figures
			1.0000    has 5 significant figures
			-1.00001   has 6
			1.23e+13   has 3
		*/
		bool status = readDouble(p, &val, &sigfigs);
		cout << "status=" << status << '\t' << val << " sigfigs=" << sigfigs << '\n';
	}
}
