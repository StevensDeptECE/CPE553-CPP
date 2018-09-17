#include "DivByZero.hh"
using namespace std;

int main() {
	int x = 2, y = 0;
	try {
		if (y == 0) {
			throw DivByZero(__FILE__, __LINE__);
		}
		int z = x / y;
	} catch (DivByZero& e) {
		cout << e << '\n';
	}
	
}
