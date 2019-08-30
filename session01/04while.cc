#include <iostream>
#include <cstdint>
using namespace std;
int main() {
	int x = 0;
	while (x < 10  ) {
		cout << x;
		x++; //x = x + 1; x += 1; ++x;
		//		x += x++; //legal?
	}
	int count = 1;
	while (count <= 10) {
		cout << count;
		count++;
	}
	
	int y = 0;
	while (y < 10)
		cout << y++ << endl; 

	int z = 10;
	while (z < 10) {
		cout << z;
		z++;
	}

	int w = 0;
	while (w < 10)
		cout << ++w;
	
}
