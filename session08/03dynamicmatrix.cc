#include <iostream>
#include <memory.h>
using namespace std;

class Matrix {
private:
  int rows, cols;
	double* m;
public:
	Matrix(int rows, int cols, double val = 0) : rows(rows), cols(cols),
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

};

#if 0
// this is illegal: we are reutrning a reference to a variable that is going away
int& f() {
	int x = 2;
	return x;
}
#endif

int& f(int& x) {
	return x;
}
int main(){
	Matrix a(4,3); // create 4x3 matrix all zero
	Matrix b(4,3, 1.0);
	Matrix c = b;
	Matrix d(2,2,3.5);
	a = c = d;
	cout << c;
  int w,x,y,z;
	w = x = y = z = 0;
	int& r = f(w); // function f returns a reference to the variable that was passed to it
}
