#include  <iostream>
#include <cmath>
using namespace std;

int main() {
	double a = 3 + 1 / 2;
	double b = a * 1.5;
	int c = 4.6 * 3; 
	int d = 2 / 3.0 * 3;
	int	e = (int)b * 3; 
	int f = (int)(b * 3);
	int g = int(b * 3);
	int h = round(b*3);
	int i = floor(b*3);
	int j = ceil(b*3); 
  int k = 3 + 1.0 / 2 * 4 - 6;

	cout << "a=" << a << '\n';
	cout << "b=" << b << '\n';
	cout << "c=" << c << '\n';
	cout << "d=" << d << '\n';
	cout << "e=" << e << '\n';
	cout << "f=" << f << '\n';
	cout << "g=" << g << '\n';
	cout << "h=" << h << '\n';
	cout << "i=" << i << '\n';
	cout << "j=" << j << '\n';
	cout << "k=" << k << '\n';
}
