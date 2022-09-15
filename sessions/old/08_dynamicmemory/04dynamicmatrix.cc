#include <iostream>
#include <memory.h>
using namespace std;

class Matrix {
private:
  int rows, cols;
	double* m;
	Matrix(const char* foo, int rows, int cols) : rows(rows), cols(cols),
															 m(new double[rows*cols]) {}
	
public:
	Matrix(int rows, int cols, double val) : rows(rows), cols(cols),
																							 m(new double[rows*cols]) {
    for (int i = 0; i < rows*cols; i++)
			m[i] = val;
	}
	~Matrix() {
		delete [] m;
	}
	Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols),
															 m(new double[rows*cols])
	{
		for (int i = 0; i < rows*cols; i++)
			m[i] = orig.m[i];
	}
	Matrix& operator =(const Matrix& orig) {
		Matrix copy(orig); // copy and swap paradigm
		this->rows = copy.rows;
		this->cols = copy.cols;
		swap(this->m, copy.m);
		return *this;
	}
  friend Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || b.cols != b.cols)
			throw "Bad size";
		Matrix ans("yoho!", a.rows, a.cols);
		for (int i = 0; i < rows*cols; i++)
			ans.m[i] = a.m[i] + b.m[i];
		return ans;
	}
	Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols),
													m(orig.m){
		orig.m = nullptr;
	 
	}

	double operator ()(int r, int c) const {
		return m[r * cols + c];
	}

	double& operator ()(int r, int c) {
		return m[r * cols + c];
	}
};

int main(){
	Matrix a(4,3); // create 4x3 matrix all zero
	Matrix b(4,3, 1.0);
	Matrix c = a + b;
	c(1,3) = 2.5;
	cout << c(1,2);
}
