#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// algebra: f(x) = x^2


int f(int x) { return x*x; }
double f(double x) { return x*x; }
// two functions named the same with different parameters called "function overloading"

double hypot(double a, double b) {
  return sqrt(a*a + pow(b,2));
}

double fact(int n) {
    double factorial = 1;
    for(int a = 1; a <= n; a++){
      factorial *= a;
    }
    return factorial;
}



int main() {
  double z = f(1.5);
  int y = f(3);
  double w = f(4);
  double a = 3 / 2;
  cout << setprecision(16);
  for (int i = 1; i < 200; i++)
    cout << fact(i) << '\n';
}