#include <iostream>
using namespace std;
inline double f(double x) {
	return x*x;
}

int f(int x) {
	return x*x;
}

int main() {
	cout << f(2.0) << "\n";
	cout << f(2) << "\n";
}
