#include <iostream>
using namespace std;

int main() {
	int x[] = {1, 3, 5, 9, 2, 7};
	int y[10] = {5, 3, 2};
	int* p = &x[2];
  int a;

  *++p = -2; // x[3  ] = -2
	a = ++*p; x[3] = x[3] + 1 = -1   a=-1
	a = (*p)++;  a = -1   x[3] = 0
  *p++ = 5;  // *p = 5; p++;

	int z[5] = {6, 1, 8}; // 6 6 8 0 0 
	p = z + 1; // p points to z[1] which is 1
	*p++ = 9; // *p = 9  p = &z[2 ]
	*--p = 5; // --p p=&z[1]  *p = 5
	++*p;  // *p is z[1]
	
  float w[5] = { 3, 5, 7};
	float *fp = w;
	for (int i = 0; i < 4; i++)// 1.5 2.5 3.5 0 0 
    *fp++ /= 2;
	for (int i = 0; i < 3; i++)// 1.5 1.5 2.5 -1 0
	  *--fp -= 1;
	for (int i = 0; i < 2; i++)// 1.5 1.5 7.5 -3 0
	  *++fp *= 3;
}
