#include <iostream>
#include <fstream>
using namespace std;

func(int* p) {


}

void func(int& r) {

}







int main() {
	ifstream f("myfile.webp", ios::binary);
	f.seekg(0, ios::end);
	int len = f.tellg();
	uint8_t* p = new uint8_t[len];
	f.read(p, len);
	// skip the header
	int skip = 98;
	webpdecodeRGBA(p+skip,...);
}
