#include <iostream>
using namespace std;

int main() {
	for (int i = 3; i <= 23; i += 2)
	  cout << i;
	cout << '\n';  

	for (int i = 3; i <= 42; i *= 2)
	  cout << i;
	cout << '\n';  

#if 0
	for (uint16_t i = 0; i < 100000; i++)
		cout << i;
	cout << '\n';  
#endif

	for (int i = 0; i > 10; i++)
		cout << i;
	cout << '\n';
	
	for (int i = 10; i < 10; i--)
		cout << i;
	cout << '\n';

#if 0
	for (int i = 100; i > 0; i = i / 3 + 1)
		cout << i;
	cout << '\n';
#endif

	for (int i = 0, j = 23; i < 10; i++, j--)
		cout << j; // 23 22 21 20 19 18 17 16 15 14
	cout << '\n';

  double a = 3.0, b = 5.0;
	double x = a;
	const int n = 600;
	float dx = (b - a) / n;
	for (int i = 0; i <= n; i++, x += dx)
		cout << x << ' '; // 3 3.5 4 4.5 5 the 5 may not be perfectly accurate, but at least it will go
	cout << '\n';
	
	// this way is NOT GOOD. It will miss the last number
	for (double x = a; x <= b; x += dx)
	  cout << x << ' ';
	cout << '\n';

}



