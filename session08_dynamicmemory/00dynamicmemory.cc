#include <iostream>
using namespace std;

void f() {
	int x =2;
  int* p = new int[10]; // memory leak
}
int main() {
	int a; // not dynamic
	int b;
	int x[10];

	int n;
	cin >> n;
	//	int y[n];
	int *y = new int[ n ]; //allocate memory on the heap
	//  int *p = new int [256ULL*1024*1024*1024  ];// https://stackoverflow.com/questions/58523977/is-it-possible-to-allocate-large-amount-of-virtual-memory-in-linux
  f();
	//	y[3]
	//	y[-3]

	delete [] y;


	int a;
	int* q = &a;
	delete q; //ERROR! you can only delete memory that was allocated with new

	int *b = new int;
	delete b;
	delete b; // deleting twice will crash! BOOM!!!
	
  int* c = new int[10];

	c++;
	delete [] c; // BOOM!
	
	
