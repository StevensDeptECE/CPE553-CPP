#include <iostream>
using namespace std;

void init(int*p, int len, int val) {
  while (len > 0) {
    *p = val;
    p++;
    len--;
  }
}


void print(const int* val, int len) {
    for(int i = 0; i < len; i++) {
        cout << *val;
        val++;
    }
}



int main() {
  int x[10];  //  x--> x[0]  x[1]  x[2]  x[3] ...  x[9]
  init(x, 10, 3);
  print(x, 10);

   //                                         p
  int* p = x + 2; // int*p = &x[2] // 3   3   3   3   3   3   3   3   3   3   3
  for (int i = 0; i < 5; i++) {
    *p += 2;
    p++;
  }// 3   3   10   10   10   5   5   3   3   3   3

  p = &x[5];
  for (int i = 0; i < 3; i++)
    *--p *= 2;

  print(x, 10);

  char s[] = "this is a test. This is a lot of bytes";
  int* q = (int*)s;
  cout << *q;

  q = (int*)(s+1); // different number, and NOT ALIGNED
  cout << *q;

  float* pf = (float*)s;
  cout << *pf;



}