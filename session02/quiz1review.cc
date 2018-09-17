#include<iostream>
using namespace std;

void f(int n) {
	int sum;
	for (int i = 1; i <= n; i++)
		sum += i;
	cout << sum << '\n';
}

void g() {
	int a = 991;
	int b[] = {1, 2, 3, 99};
	float x = 1.2;
	double y = 6.02e+23;
	cout << "yoho!\n";
}

int main() {
	int n;
	cout << "please enter n: ";
	cin >> n;
	g();
	f(n);
	int prod = 1;
	for (int i = 1; i <= n; i++)
		prod = prod * i;

#if 0
	double sum2 = 0;
	for (int i = 1; i <= n; i++) /* comment */
		sum2 = sum2 + 1.0/i;
#endif

#if 0
	double sum2 = 0;
	for (double i = 1; i <= n; i++)
		sum2 = sum2 + 1/i;
#endif

#if 0
	double sum2 = 0;
	for (double i = 1; i <= n; i++)
		sum2 = sum2 + 1.0/i;
#endif

	double sum2 = 0;
	for (int i = 1; i <= n; i++)
		sum2 = sum2 + 1/double(i); // cast    old C: (double)i
}
