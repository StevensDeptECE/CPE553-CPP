#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	//	int x[10000000];
	int* p = new int[10000000];
	delete[] p;
  p[2] = 2;
	cout << p[2];
	
	//	delete [] p;
	
	int* q = new int;

	delete q;

	int* r =(int*) malloc(1024);

	free(r);
}
