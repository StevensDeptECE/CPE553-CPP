#include <iostream>
using namespace std;

int f() {
  int temp = 5;
  for (int i = 0; i < 10; i++)
    temp = temp * 4 + i;
  return temp;
}

int* g() {
  int temp = 5;
  for (int i = 0; i < 10; i++)
    temp = temp * 4 + i;
  return &temp;
}


void first() {
  int b[20] = {96, 1, 2};
  int y = f();
  cout << y << '\n';
  int*p = g();
  y = *p;
  cout << y << '\n';
}

int main() {
  int a[100];
  first();
}