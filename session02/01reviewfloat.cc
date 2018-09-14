#include  <iostream>
using namespace std;

int main() {
	cout << 24 * 60 * 60 << '\n';
	cout << 1 * 365 * 24 * 60 * 60 << '\n';
	cout << 20 * 365 * 24 * 60 * 60 << '\n';
	cout << 52 * 365 * 24 * 60 * 60 << '\n';
	cout << 52 * 365 * 24 * 60 * 60 << '\n';
	cout << 68 * 365 * 24 * 60 * 60 << '\n';
	cout << 69LL * 365LL * 24LL * 60LL * 60LL << '\n';

	long long secondsIn69Years = 69LL * 365 * 24 * 60 * 60;
	int a = 2;
	float b = a + .5; //2.5 conversion to float no problem
	int c = b; // c ==2
	int d = int(b);
	double e = 69.0 * 365.2425 * 24 * 60 * 60; // 1.2312512512516e+300
	cout << e << "\n";
	69.0 * 365.0f * 22L * 3;
	double Na = 6.022E+23;
	double big = 1.23456789012345e+308;
	double tiny = 1.23456789012345e-308;
	long long x = 12345678901345678;
	
	
}
