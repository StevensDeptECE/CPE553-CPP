#include<iostream>
using namespace std;

void fill(int* p, int n) {
  for (int i = 0; i < n; i++)
    p[i] = 0;
}

void fill2(int*p, int n) {
  for (int i = 0; i < n; i++)
    *p++ = 1;
}

void doubleme(int*p, int n) {
  for (int i = 0; i < n; i++)
    *p++ *= 2;
}

void doubleme(int* const p, int n) {
  for (int i = 0; i < n; i++) {
    *(p + i) *= 2;
    p[i] *= 2;
  }
}

void reverse(int*p, uint32_t n) {
  uint32_t end = n / 2;
  for (int* q = p + n - 1; end > 0; end--, p++, q--)
    swap(*q, *p);
}

void removeEven(int*p, int n) {

  for (int*q = p; n > 0; n--, p++)
    if (*p % 2 == 0)
      ;
    else {
      *q++ = *p;
    }
}

void print(const int* p, int n) {
  for (int i = 0; i < n; i++)
    cout << *p++ << ' ';
  cout << '\n';
  for ( ; n > 0; n--, p++)
    cout << *p;
  cout << '\n';
}


void copy(int*dest, int* src, int  n) {
  for ( ; n > 0; n--, dest++, src++)
    *dest = *src;

  for (int i = 0; i < n; i++)
    dest[i] = src[i];
}

int main() {
  int x[10];
  fill(x, 10);
  fill2(x, 10);

  int a[] = { 9, 8, 6, 4, 2}; // --> 2, 4, 6, 8, 9
  reverse(a, 5);


  int b[] = { 1, 4, 3, 2, 9, 7, 8, 5}; //--> 1, 3, 9, 7, 5
  removeEven(b, 8);
  print(b, 8);

  int c[8];
  copy(c, b, 8);
  
