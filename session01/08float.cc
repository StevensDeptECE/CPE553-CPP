#include <iostream>
using namespace std;
/*
  floating point is in binary

  we are used to thinking of "nice" numbers 1/10   0.1    1/2  0.5
  numbers are repeating fractions: 1/3 = .33333333

but on a computer, 0.1 is not a "nice" fraction.

1/10 = 1/2 * 1/5
       	1/2  1/4   1/8   1/16   1/32
0.5    .1     0     0     0      0
0.1    .0     0     0     1      0      1     0     1     0    1













 */
int main() {
	for (float i = 0; i <= 10; i++)
		cout << i << ' ';
	cout << '\n';
	// type promotion 0 --> 0.0f
	for (float i = 0; i <= 10; i += 0.1)
		cout << i << ' ';
	cout << '\n';

	for (float i = 0; i <= 1000; i += 0.1)
		cout << i << ' ';
	cout << '\n';

}
