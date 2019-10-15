#include <iostream>
using namespace std;

int main() {
  int a = 3;
  int b = 4;
  int*r = &b;
  *r++;
  int* p = &a;
  int x[6] = {9,2,7};
  p = x + 2; // or p = &x[0] + 2
  cout << *p << '\n';                // _____________________________
  int q = *p++; // p points to x[3]
  int* s = &q;
  *s = 22;
  *p++ = 11; // x[3] = 11, p = &x[4]
  *--p += 3; // p = &x[3] *p += 3  x[3] = 14
	int j = --*p;  // j = x[3] = 13
	//int j = (*p)--;  // j = 14, x[3] = 13
  cout << j << '\n';
  for (int i = 0; i < b; i++)
    cout << x[i] << ',';             // _____________________________
  cout << '\n';
}

void zeros(int*p, int n) {
  for (int i = 0; i < n; i++)
		*p++ = 0;

	for ( ; n > 0; n--)
		*p++ = 0;
}

void print(const int* p, int n) {
	for (int i = 0; i < n; i++)
		cout << *p;
}




  
