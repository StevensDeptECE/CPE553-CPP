#include <iostream>
using namespace std;

int main() {
  int a[10] = {1, 2, 3, 5, 9, 4};
  for (int i = 0; i < 10000; i++) { // yes, it's crazy to go 10000 times,
    if (i < 10 & a[i] % 2 == 0) // but isn't this doing it only for 1st 10?
      cout << a[i] << ' ';
  }
  cout << "\n";
}
