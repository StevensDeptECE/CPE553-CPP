#include <iostream>
using namespace std;

int main() {
  int a[1024]; // located where? on the stack! (auto)
  int b[4096*1024];
  int*p = (int*)malloc(1024*sizeof(int));
  p[-2] = 2048; // low  high  

  free(p);

  p = new int[1024];
  //  for (int i = 0; i < 2024; i++)
  //    p[i] = 99;

  delete [] p;

  p = new int[1024*1024*1024];

  delete [] p;
}
