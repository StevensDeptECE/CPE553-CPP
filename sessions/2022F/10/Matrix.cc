#include <iostream>
#include <cmath>

class Ex {
private:
  int linenum;
  const char* filename;
  const char* msg;
public:
  Ex(int linenum, const char* filename, const char* msg) :
   linenum(linenum), filename(filename), msg(msg) {}
   friend std::ostream& operator<<(std::ostream& s, const Ex& e) {
     return s << e.filename << " " << e.linenum << ":" << e.msg << '\n';
   }
};

class Matrix {
private:
  uint32_t rows, cols;
  double* m;
  Matrix(uint32_t rows, uint32_t cols, const char*) : rows(rows), cols(cols),
  m(new double[rows*cols]) {}
public:
  //Default constructor
  Matrix(uint32_t rows, uint32_t cols, double val = 0)
   : rows(rows), cols(cols), m(new double[rows*cols] ) {
    for (uint32_t i = 0; i < rows*cols; i++)
      m[i] = val;
  }
  //Destructor
  ~Matrix() {
    delete [] m;
  }
  //Copy constructor
  Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols),
     m(new double[orig.rows * orig.cols]) {
    memcpy(m, orig.m, sizeof(double) * rows * cols);
  }
  //Overloading = operator
  Matrix& operator =(Matrix copy) {
     rows = copy.rows;
     cols = copy.cols;
     std::swap(m, copy.m);
     return *this;
  }
  //Move constructor
  Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
    orig.m = nullptr;
  } 
  //Overloading () operator 
  double operator ()(uint32_t r, uint32_t c) const {
     return m[r * cols + c];
  }

  double& operator () (uint32_t r, uint32_t c){
     return m[r * cols + c];
  }
  //Overloading << operator
  friend std::ostream& operator <<(std::ostream& s, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++)
          s << m(i,j) << '\t';
        s << '\n';
    }
    return s;
  }
  friend Matrix operator +(const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows || a.cols != b.cols)
      throw Ex(__LINE__, __FILE__, "Matrices not same size");
    Matrix ans(a.rows, a.cols, "unintialized");
    #if 0
    for (int i = 0; i < a.rows; i++)
      for (int j = 0; j < a.cols; j++)
        ans(i,j) = a(i,j) + b(i,j);
#endif
    for (int i = 0; i < a.rows*a.cols; i++)
      ans.m[i] = a.m[i] + b.m[i]; 
    return ans;
  }
};

int main() {
    try {
    /*
    0   0   0   0
    0   5   2.2 0
    0   0   0   0
    */
    Matrix m1(3,4);
    std::cout << m1 << '\n';
    m1(1,1) = 5.0;
    m1(1,2) = 2.2;
    Matrix m2 = m1;
    m2(3,2)=9.1;
    m1 = m2;
    //...
    Matrix m4 = m1 + m2;
    std::cout << m4;
    Matrix m3(4,5); 
    m1 = m3 + m4;
    m1(19,45) = 99;// problem!
    } catch(Ex& e) {
        std::cout << e;
    }
}