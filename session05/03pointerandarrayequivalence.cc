#include <iostream>
using namespace std;

int main() {
  int x[10]; // x can only point to this block of memory (Fixed)
  x[0] = 5;
  int* const p = x; // p and x are the same (const pointers to int)

  cout << x[0] << p[0] << '\n';
	p[0] = 22;
	//	p++; // cannot move p

  const int y[10] = {3};
	//	int* p = &y[0]; // error: *p = 99;
	const int* q = &y[0]; // y + 0 // y
	cout << *q;
	//ERROR: *q = 55;
	
  const int* const r = y; // r and y are the same
  cout << y[0] <<'\n';
  /// illegal, y[] is const  y[0] = 55;
  //  *r = 55;
	//	r = x; // cannot change r

  // what is the difference between x and y?
  // what is the difference between p and q?
}
