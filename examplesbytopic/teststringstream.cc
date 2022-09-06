#include <iostream>
#include <sstream>
using namespace std;

int main() {
	//	char buf[1024];
	//	string str;
	//	str.reserve(1024); // preallocate enough memory
	ostringstream f;//str, std::ios_base::ate);
	for (int i = 0; i < 10; i++)
		f << i << "hello";
	cout << f.str() << '\n';
	return 0;
}
