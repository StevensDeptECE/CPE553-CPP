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
  cout << *p << '\n';  // 7 _____________________________
  int q = *p++;        // q=*p; p++ q = 7, p points to x[3] which is 0
  int* s = &q;
  *s = 22;             //q = 22 *p still zero
  *p++ = 11;           // *p=11; p++   x[3] = 11
  *--p += 3;           // --p; *p += 3   p points to x[2] x[2] += 3
	int j = --*p;        //
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




  
