#include <iostream>
using namespace std;
int main() {
  int x[10] = {1, 257, 65536*2+1, 1001};
  char* p = (char*) x;

// 1 0 0 0  1 1 0 0             0 0 0 1
  for (int i = 0; i < 12; i++) {
    cout << i << ": " << p[i] << '\n';
  }
  for (int i = 0; i < 12; i++) {
      cout << i << ": " << (int)p[i] << '\n';
  }


}