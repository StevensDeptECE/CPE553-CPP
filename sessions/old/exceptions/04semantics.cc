#include <iostream>
using namespace std;

class Zebra {
public:
	Zebra() { cout << "Zebra is born!\n"; }
	~Zebra() { cout << "Zebra is dying!\n"; }
};

void g(int x) {
	if (x == 0)
		throw "div by zero";
	int a = 1 / x; 
	cerr << " it worked!\n";
}
void f(int x) {
	Zebra z;
	g(x);
}
int main() {
	int x = 0;
	bool failed = true;
	do {
		try {
			f(x);
			failed = false; // made it
		} catch(const char* msg) {
			cout << msg << '\n';
		}
		x++;
	} while (failed);
}
