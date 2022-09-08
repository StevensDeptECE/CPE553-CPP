#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char buf[1024];
	ifstream f("lines.txt");
	while (f.getline(buf, sizeof(buf)-1)) {

	}
}
