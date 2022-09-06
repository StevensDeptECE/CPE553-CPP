#include <iostream>
using namespace std;

class A {
public:
	A() { p = new int[n]; }
	~A() { delete [] p

};

int main() {
	int x[5]; // size= 4*5 (20 bytes)
	int n;
	cin >> n;
	//	int y[n];
	for (int i = 0; i < 100000; i++) {
		int* y = new int[n]; // allocate a block of n elements (uninitialized)
	

		//	int z[n][10]; // n * 10 * sizeof(int) = n * 40
		//NO WAY:		int z[n][n];


	
		delete [] y;

		int*  p = new int;
		delete p;

		int* q = malloc(1024*sizeof(int));
		free(q);
		
	}
}
