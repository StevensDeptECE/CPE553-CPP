#include <iostream>
#include <memory.h>
using namespace std;

class Matrix {
private:
  uint32_t rows, cols;
  double* m;
public:
  Matrix(uint32_t rows, uint32_t cols, double v = 0.0)  : rows(rows), cols(cols), m(new double[rows*cols]) {
      for (int i = 0; i < rows*cols; i++)
        m[i] = v;
  }
  ~Matrix() {
      delete [] m;
  }
  Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), m(new double[orig.rows*orig.cols ]) {
      memcpy(m, orig.m, rows*cols*sizeof(double));
  }
  Matrix& operator =(Matrix orig) {
    rows = orig.rows;
    cols = orig.cols;
    swap(m, orig.m);
    return *this; // dereference this object  = ME, self
  }
  Matrix(Matrix&& m) : rows(m.rows), cols(m.cols), m(m.m) {
    m.m = nullptr;
  }

  /*
      0   1   2   3
      4   5   6   7
      8   9  10  11
      double x[3][4]; // row major order
  */
  double operator ()(uint32_t r, uint32_t c) const {
      return m[r*cols + c];
  }
  double& operator ()(uint32_t r, uint32_t c) {
      return m[r*cols + c];
  }
  static Matrix ident(uint32_t n) {
      Matrix m(n,n);
      for (uint32_t i = 0; i < n; i++)
        m(i,i) = 1.0;
     return m;
  }
  friend ostream& operator <<(ostream& s, const Matrix& m) {
    uint32_t c = 0;
    for (uint32_t i = 0; i < m.rows; i++) {
        for (uint32_t j = 0; j < m.cols; j++, c++)
           s << m.m[c] << '\t';
        s << '\n';
    }
    return s;
  }
};


int main() {
    Matrix a(3,4); // default to 0
    Matrix b(3,4, 1.0);
    b(0,0) = 2.5;
    a(1,2) = 1.5;
    cout << a << '\n';
    Matrix c = a;
    Matrix d = Matrix::ident(3); // 3 x 3 identity matrix
    cout << d << '\n';
    d = c;
    a = b = c = d;
    cout << d << '\n';
}