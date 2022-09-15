#include <iostream>
using namespace std;

int main() {
	double d = 1.5152124151251;
	float f = (float) d;
	float f2 = float(d);
	//	Fraction f1(1,2);
	//	int i = int(f1);
  int a = 1000000;
  double* p;
  //  p = &a; // this doesn't work.the compiler knows I am being stupid
  p = (double*)&a;
  // new notation does not work for pointers: p = double*(&a)
	// [ a a a a ]
	//	     ^
  cout << *p << '\n';
}
