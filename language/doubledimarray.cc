#include <iostream>
#include <cstdint>
using namespace std;

class Matrix {
private:
  uint32_t rows, cols;
  double* m;
  
public:
  Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), m(new double[rows*cols]) {
    for (int i = 0; i < rows*cols; i++)
      m[i] = 0;
  }
  ~Matrix() {
    delete [] m;
  }
  Matrix(const Matrix& orig);
  Matrix operator =(const Matrix& orig);

};



int main() {
  int m, n;
  cin >> m >> n;
  int a[m][n];

  for(int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = 0.0;
  const char* p = "testing testing 1234";
  cout << strlen(p) << '\n';
  string s = p;
  


}

  
