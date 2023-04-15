#include <iostream>
using namespace std;

class matrix {
private:
  uint32_t rows, cols;
  double* val;
public:
  matrix(uint32_t r, uint32_t c, double v) : {}
  ~matrix() {}
  matrix(const matrix& orig) : {}
  void set(uint32_t r, uint32_t c, double v) {}

  //TODO: use copy and swap paradigm
  matrix& operator =(matrix copy) {
    //TODO: 
    return *this;
  }
};

int main() {
  matrix m1(3,4, 0.0); // 3*4 = 12 double, set each one to 0.0
  m1.set(0,0, 1.5);    // set element m1(0,0) = 1.5
  //later: m1(0,0) = 1.5;

  cout << m1 << '\n';
  matrix m2 = m1;
  m2.set(1,3) = 9.2;
  cout << m2 << '\n';
  m2 = m1; // should wipe out the copy
  cout << m2 << '\n';
}