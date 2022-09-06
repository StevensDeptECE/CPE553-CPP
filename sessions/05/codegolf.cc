#include <iostream>
using namespace std;

void collatz(int n) {
  while ( n > 1 ) {
    if (n % 2 == 0) {
      cout << n << ' ';
      n = n / 2;      
    } else {
      cout << n << ' ';
      n = n * 3 + 1;
    }
  }
}

void collatz2(int n) {
  while ( n > 1 ) {
    cout << n << ' ';
    if (n % 2 == 0) {
      n /= 2;      
    } else {
      n = n * 3 + 1;
    }
  }
}

void collatz3(int n) {
  while ( n > 1 ) {
    cout << n << ' ';
    n = (n % 2 != 0) ?  n * 3 + 1 : n / 2;
  }
}

void collatz4(int n) {
  for ( ; n > 1 ; n = (n % 2 != 0) ?  n * 3 + 1 : n / 2)
    cout << n << ' ';
}


int main() {
  int n;
  cin >> n;
  collatz(n); // ex: 13 40 20 10 5 16 8 4 2 1


}