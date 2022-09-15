#include <iostream>
using namespace std;

int f(int n) {
	if (n == 0)
		throw "Div by zero";
	return 1 / n;
}

int g(int x) {
	return f(x);
}

int main() {
	try {
		cout << f(3) << '\n';
		int x = 0;
		bool retry = false;
		do {
			try {
				cout << g(x)  << '\n';
			} catch (const char* msg) {
				x++;
				retry = true;
			}
		} while(retry);
	} catch(const char* msg) {
		cout << "Error: " << msg << '\n';
	}
}
	
