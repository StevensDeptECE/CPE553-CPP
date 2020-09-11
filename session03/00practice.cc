#include <iostream>
using namespace std;

double sumSquares(int x, int y){ //Computes the sum of all squares from x to y
  double sum = 0; //Double stores larger numerical values than int (avoids overflow)
  for (int i = x; i <= y; i++){
    sum += i * i;
  }
  return sum;
}

double factorial(int a)
{
    double answer = 1;
    for(int i = 1; i <= a; i++)
    {
        answer *= i;
    }
    return answer;
}

double factorial2(uint32_t n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial2(n-1);
}

int fibonacci(int n) {
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
    int a = 1, b = 0, c;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

//recursive with memoization (also called dynamic programming)
double fibo2(int n) {
    if ( n <= 2 ) {
        return 1;
    }
    static double memo[200] = {0};
    if (memo[n] != 0)
      return memo[n];

    return memo[n] = fibo2(n-1) + fibo2(n-2);
}

int main() {
    cout << sumSquares(5, 8) << '\n';
    cout << factorial(5) << '\n';
    cout << factorial2(5) << '\n';//new (recursive)
    cout << fibonacci(5) << '\n';//loop
    cout << fibo2(5) << '\n';//recursive
    cout << fibo2(10) << '\n';//recursive
    cout << fibo2(20) << '\n';//recursive
    cout << fibo2(30) << '\n';//recursive
    cout << fibo2(40) << '\n';//recursive
    cout << fibo2(50) << '\n';//recursive
}
