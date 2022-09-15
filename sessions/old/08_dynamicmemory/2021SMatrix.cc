class Matrix {
private:
  uint32_t rows,cols;
  double* m;

  public:
  Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), m(new double [rows*cols]) {
    for (int i = 0; i < rows*cols; i++)
      m[i] = 0;
  }

  friend Matrix operator *(const Matrix& a, const Matrix& b) {
    if (a.cols != b.rows)
      ; // really bad
    Matrix ans(a.rows, b.cols);

    for (int k = 0; k < b.rows; k++)
      for (int j = 0; j < b.cols; j++) {
        ans(k, j) = 0;
        for (int i = 0; i < a.cols; i++)
          ans(k,j) += a(k,i) * b(i,j);
      }
  }


};

int main() {
  /*
    m1 = 0 0 0
         0 0 0

    m2   0 0 0 0
         0 0 0 0
         0 0 0 0
 
      1 2 3   *    1 -2 -3  2    x  y
      2 3 4        2 -1  0  1 = 
                   3 -3  -2 1

  */
   Matrix m1(2, 3);
   Matrix m2(3, 4);
   Matrix m3 = m1 * m2;
}