#include <iostream>

class matrix {
private:
  int n;
  double* m;
public:
  matrix(int n) : n(n), m(new double[n*n]) {
    for (int i = 0; i < n*n; i++)
      m[i] = 0;
  }

/*

x x x x
x x x x
x x x x
x x x x

(inside memory it just looks like ( x x x x x x x x x x x x x x x x ) in a straight line; we want to skip r*n elements to get to the "row" we want)
*/
  void set(int r, int c, double v) {
    m[r*n + c] = v;
  }
  
  double& operator() (int r, int c) {
    return m[r*n+c];
  }
  double operator() (int r, int c) const {
    return m[r*n+c];
  }
};

int main() {
  matrix m1(5);
  m1(2,3) = 19;
  m1.set(2,3,19);
  std::cout << m1(2,3) << '\n';
}