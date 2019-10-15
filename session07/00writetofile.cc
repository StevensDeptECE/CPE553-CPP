#include <iostream>
#include <fstream>

using namespace std;
int main() {
	ofstream f("test.stl");
	f << "hello" << 5 << '\n';

	ifstream in("solarsystem.dat");
	// sun 1e30 x 0.0
	string name;
	double mass;
	in >> name >> mass >> radius >> perihelion ...;

}
	
