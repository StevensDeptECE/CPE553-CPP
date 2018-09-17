#include  <iostream>
#include <cmath>
using namespace std;

int main() {
	double x = 3 + 1 / 2; //0 --> 0.0
	double y = x * 1.5;
	int z = y * 3; // 4.5 * 3 ==> 13.5 --> 13
	int w = round(y*3);
	cout << x << ' ' << y << ' ' << z << '\n';
	
}
