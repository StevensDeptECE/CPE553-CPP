#include <iostream>
#include <cstdint>
using namespace std;

double factorial(int n) {
  if (n <= 0)
    return 1;
  return n * factorial(n-1);
}

//  count(0) = 0;
//  count(5) = 1 + count(4)  
int count(int n) {
  if (n == 0) {
    return 0;
  }
  return 1 + count(n-1);
}

// 1, 1, 2, 3, 5, 8, 13, 21, ...
uint64_t fibo(int n) {
    uint64_t a = 1;
    uint64_t b = 1;
    uint64_t c;
    for (int i = 1; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
}
/*
    fibo(10) = fibo(9) + fibo(8)
               /              \
              /                \
        fibo(8)+fibo(7)        fibo(7)+fibo(6)

*/
uint64_t fibo2(int n) {
  if (n <= 2) {
    return 1;
  }
  return fibo2(n-1) + fibo2(n-2);
}


int main() {
    for (int i = 0; i < 30; i++) {
        cout << i << ":\t" << factorial(i) << '\n';
    }
    int n;
    cin >> n;
    cout << fibo2(n);

}