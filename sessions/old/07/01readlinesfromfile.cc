#include <iostream>
#include <fstream>
#include <sstream> // string stream
#include <string>
using namespace std;

void alt() {
	ifstream f("test2.dat");
	char buf[4096];
	while (!f.eof()) {
		f.getline(buf, sizeof(buf));
		istringstream line(buf);
    
	}
}

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
	alt();
}
