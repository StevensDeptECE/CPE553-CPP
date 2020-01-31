#include  <iostream>
#include <cmath>
using namespace std;

int main() {
	double x = 3 + 1 / 2; // 3+ 0 ==> 3 --> 3.0
	double y = x * 1.5; // 4.5
	int z = 4.6 * 3; // 4.6 * 3.0 ==> 13.8 --> 13
	z = (int)y * 3; // 4*3 = 12
	int z = (int)(y * 3); // 4.5 * 3.0 = 13.5  int(13.5) = 13
	int z = int(y * 3); // 4.5 * 3.0 = 13.5  int(13.5) = 13
	int w = round(y*3); // 13.5 --> 14.0 --> 14
	w = floor(y*3); // 13
	w = ceil(y*3); //14
	cout << x << ' ' << y << ' ' << z << '\n';
	
}
