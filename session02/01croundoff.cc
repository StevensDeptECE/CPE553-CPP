#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << setprecision(15);
	for (double x = 0; x <= 100; x = x + .1)
		cout << x << ' ';
	cout << '\n';
}
