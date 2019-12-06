#include <memory.h>

class Matrix {
private:
  int rows, cols;
	double* m;
public:
	Matrix(int r, int c, double v) : rows(r), cols(c), m(new double[r*c]) {
		for (int i = 0; i < r*c; i++)
			m[i] = v;
	}
	
	Matrix(const Matrix& orig)
		: rows(orig.rows), cols(orig.cols), m(new double[orig.rows*orig.cols]) {
		memcpy(m, orig.m, sizeof(double)*rows*cols);
	}
	
	~Matrix() {
		delete [] m;
	}
  Matrix& operator =(Matrix copy) {
		rows = copy.rows;
		cols = copy.cols;
		swap(m, copy.m);
		return *this;
	}
  Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
		orig.m = nullptr;
	}
};

void f(Matrix m) {

}

int main() {

	/*
		0 0 0 0
    0 0 0 0
    0 0 0 0
	 */
	Matrix m1(3,4, 0.0); 

	/*
		1.5 1.5 1.5 1.5
		1.5 1.5 1.5 1.5
		1.5 1.5 1.5 1.5
	*/
	Matrix m2(3,4, 1.5);
	Matrix m3 = m1 + m2;
	//	Matrix m4 = m1 * m2;

	Matrix m4 = m2; // copy constructor
	int a = 2; // initialization
	a = 3; // operator = changes value to 3
  f(m4);	
}
