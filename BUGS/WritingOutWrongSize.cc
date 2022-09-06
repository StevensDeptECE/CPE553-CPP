#include <iostream>
#include <fstream>
using namespace std;

void	writeOutBinaryFile(const char filename[], uint32_t);


int main() {
	int x[10];
	ofstream f("x.dat", ios::binary);
	f.write((char*)x, sizeof(x));
	f.close();
	writeOutBinaryFile("y.dat", 8*1024*1024);
}

void writeOutBinaryFile(const char filename[], uint32_t size) {
	int y[size];
	ofstream f(filename, ios::binary);
	f.write((char*)y, sizeof(y));
}

	
