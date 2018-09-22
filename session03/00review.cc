#include <iostream>
using namespace std;
void f() {
	cout << 'f' << 2 + 3 << 3 / 2 << "ti" << 5 % 3 << '\n';
}
int g(int n) {
	if (n <= 0)
		return 0;
	return n * g(n-2);
}

double factorial(int n) {
  double prod = 1;
	for (int i = 1; i <= n; i++)
		prod *= i;
	return prod;
}

double factorial2(int n) {
	if (n <= 0)
		return 1;
	return n * factorial2(n-1);
}

// do for hw
// hint use a,b,c
// fibonacci 1, 1, 2, 3, 5, 8, 13, ...
double fibo(int n) {
	

}

// recursive version    O(2^n)
double fibo2(int n) {
	static int memo[200];
	if (n <= 2)
		return 1;
	return fibo(n-1) + fibo(n-2);
}



int main() {
	5+19;
	f;
	g(2);
	f();
	int a = 2.9;
	uint16_t b = -1; // 1111 1111 1111 1111 0xFFFF = 65535   65536-1
	double c = 2 / 3;
	double d = 3 / 2 * 2.0;
	double e = 3 / 2.0 * 2;
	double f = 3 / (2 * 2.0);
	cout << 5 << ' ' << 5LL << 2.0 << " " << 2.0f << " " << 2.0L << '\n';

	cout << sizeof(float) << " " << sizeof(double) << " "  << sizeof(long double) << "\n";
	bool isThisTrue = 1 == 0.3 + 0.2 + 0.2 + 0.2 + 0.1; // NEVER use == for floating point
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << isThisTrue << '\n';
}
