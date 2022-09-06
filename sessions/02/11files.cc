#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream f("test.dat");
	double x,y;

	while (!f.eof()) {
		f >> x >> y; // this is very fragile. Bad input turns this into an infinite loop
		cout << x << '\t' << y << '\n';
	}
}
