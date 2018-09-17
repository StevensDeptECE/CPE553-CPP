#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream f("test.dat");
	double x,y;

	while (!f.eof()) {
		f >> x >> y;
		cout << x << '\t' << y << '\n';
	}
}
