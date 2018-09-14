#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream f("test.dat");
	double x,y;

	while (!f.eof()) {
		string linebuf;
		getline(f, linebuf);
		istringstream line(linebuf);
		line >> x >> y;
		cout << x << '\t' << y << '\n';
	}
}
