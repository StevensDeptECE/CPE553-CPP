#include <iostream>
using namespace std;

int main() {
   int a = 3;
   int b = a++; //b = 3, a = 4 postincrement
   int c = ++a' // c = 5, a = 5 preincrement

    int sum = 0;
    for (int i = 1; i <= 50; i++) {
        sum = sum + i; // sum += i;
    }
    cout << sum << '\n';

    int prod = 1;
    for (int i = 1; i <= 5; ++i)
      prod = prod * i; // prod *= i;
    cout << prod << '\n';
    
}