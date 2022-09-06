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
  for (int i = 0; i < 10000000; i++)
    f(); // memory leak, 40 bytes at a time
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

  Elephant* e = new Elephant();
  delete e;

  e = new Elephant[10]; // allocates 10 elephants using Elephant::Elephant()

  delete [] e; // calls the destructor 10 times Elephant::~Elephant()
  c++;
  delete [] c; // BOOM! must delete the pointer you were given!

  c = new int[5];
  c[-1] = 555;
  delete c; // BOOM! don't write before the array!
}	
	
