#include <iostream>
using namespace std;

extern int f(int a, int b);
extern int g(int a[]);

int main() {
  int y = f(5,6);

  cout << y << '\n';
  int a[5] = {5, 4, 3, 2, 1};
  cout << g(a);
}
