#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
  ifstream f("vec.txt");
	string lineBuf;
	while (getline(f, lineBuf)) { 
		istringstream line(lineBuf);
		double x,y,z;
		line >> x >> y >> z;
		cout << x << ',' << y << ',' << z << '\n';
	}
	ofstream out("test.dat");
	out << "hello";
	out << 5 + 2 << '\n';
}
