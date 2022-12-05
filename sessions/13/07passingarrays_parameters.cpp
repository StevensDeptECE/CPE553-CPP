#include <iostream>
using namespace std;

int f(const int a[], int n) {
    cout << sizeof(a) << '\n';
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];
    return sum;
}

// g is EXACTLY EQUIVALENT to f
int g(const int* const a, int n) {
    cout << sizeof(a) << '\n';
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];
    return sum;
}

int main() {
  int x[10] = {92};
  int* q = x; // pointing to the first element of x
  
  x[3] = 99;
  q[3] = 99; // same as above
  *(q + 3) = 99; // same as above

  q++; // this is something arrays cannot do


  cout << sizeof(x) << '\n';
  cout << f(x, 10) << '\n';

  int y[200] = {11,3,44};
  cout << sizeof(y) << '\n';
  cout << f(y, 200) << '\n';

}