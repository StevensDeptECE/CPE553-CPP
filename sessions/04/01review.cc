#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

int a; // global variable IS INITIALIZED TO ZERO
int b = 0;

void f() {
  int a;
  cout << a;
  cout << ::a; // global a

}

int main() {
  int a[] = {5, 3, 1};
  int b[100];
  int c[10] = {0};
//  for (int i = 0; i < 10; i++)
//    c[i] = 0;
//  memset(c, 10*sizeof(int), 0);

  double x[3][4][9]; // x[0][0][0] is first element x[0][0][1]
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 9; k++)
          x[i][j][k] = 9;
    }
  }
   memset(x, 9, 3*4*9*sizeof(double));
 double* p = &x[0][0][0];
  for (int i = 0; i < 108; i++) {
   cout << p[i] << " ";
  }
   return 0;
}