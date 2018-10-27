#include <iostream>
#include <fstream>
#include <sstream> // string stream
#include <string>
using namespace std;

int main() {
	string line;
	ifstream f("test.dat");
	string name;
	double mass;
	double dist;
	while (!f.eof()) {
		getline(f, line);
		istringstream linestr(line);
		linestr >> name >> mass >> dist;
		cout << name << '\t' << mass << '\t' << dist << '\n';
	}
}
