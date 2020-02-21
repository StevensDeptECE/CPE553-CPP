#include <iostream>
using namespace std;

int main() {
  int a[10] = {3, 4, 5};
  double b[20] = {2.5, 3.5, 4, 5.5} ;
  int *p = &a[0];  // declare a pointer p to the first element of a
  //int*  p = a;
  double *q = &b[4];
  //  double* q = b + 4;
  for (int * r = a; r < a + 10; r++)
    *r = 3;
	int* r = a;
  for (int count = 10; count > 0; count--, r++)
    *r = 4;
	*r = 5;
	
  // declare a pointer q to the fifth element of b
  //  add 1 to what p points at
  //  add 1 to what q points at
  // initialize pointer r to point at the first element of a and scan forward, setting the entire array to 3

  
}
