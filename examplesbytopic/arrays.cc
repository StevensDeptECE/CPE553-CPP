#include <iostream>
using namespace std;

int main() {
  int a = 2;
  float b = 3.5f;
  
  int c; // c is random
  int d[10] = {5, 4, 3, 2, 1, 9, 9}; // d[7] = 0 ...
  int e[20] = {0}; // all zero

  for (int i = 0; i < 15000; i++) {
    cout << d[i] << ' ';

  }
}
