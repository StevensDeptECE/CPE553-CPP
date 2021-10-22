#include <iostream>
#include <utility>
using namespace std;

class Matrix {
private:
	uint32_t rows, cols;
	double* m;

public:
	Matrix(uint32_t rows, uint32_t cols, double v) : rows(rows), cols(cols),
																									 m(new double[rows*cols ]) {
		for (int i = 0; i < rows*cols; i++)
			m[i] = v;
	}

	~Matrix() {
		delete [] m;
	}

	Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols)
															 m(new double[orig.rows * orig.cols]) {
		for (int i = 0; i < rows*cols; i++)
			m[i] = orig.m[i];
		//or, use memcpy, a bit faster
		//		memcpy(m, orig.m, rows*cols* sizeof(double));
	}

	Matrix& operator =(Matrix copy) { // pass by value makes a copy!
		rows = copy.rows;
		cols = copy.cols;
		swap(m, copy.m);
		return *this;
	}

	Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
		orig.m = nullptr;
	}
	
	/*
        1 2 3 4
        2 3 4 5


	 */
	void set(uint32_t r, uint32_t c, double v) {
		m[r*cols + c ] = v;
	}
	
};

int main() {
	// 5 row x 4 col, all elements = 2.
	Matrix m1(3, 4, 2.0);
	// set element in row 1, column 2 = 2.5
	m1.set(1, 2, 2.5);
	Matrix m2(3, 4, 3.0);// 3 row x 4 col, all elements = 3.0
	m2.set(2, 2, -1.2);// set element in row 2, column 2 = -1.2
	const Matrix m3 = m1 + m2;// use a friend to add the two matrices
	Matrix m4 = -m1;// use a friend to set m4 to the negative of m1
	const Matrix m5 = m1 - m2;// use a member operator// using the member style (not friend) define operator+ to do// nothing (just return the same value)
	const Matrix m6 = +m2;// m6 should be an exact copy of m2
	// 4x4 identity matrix, all 0 except for 1s on the main diagonal// 1 0 0 0// 0 1 0 0// 0 0 1 0// 0 0 0 1
	const Matrix m4 = Matrix::ident(4);
	m4 = m4 = m5;
};
