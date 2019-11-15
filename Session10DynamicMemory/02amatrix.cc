#include <iostream>
using namespace std;

class IllegalSize {
};

class Matrix {
private:
	uint32_t rows,cols;
	double** m;
  Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols),
																				 m(new double*[rows]) {
		for (uint32_t i = 0; i < rows; i++) {
			m[i] = new double[cols];
		}
	}
public:
  Matrix(uint32_t rows, uint32_t cols, double v) : Matrix(rows,cols) {
		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < cols; j++)
				m[i][j] = v;
		}
	}
	Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols),
															 m(new double*[rows]) {
		for (uint32_t i = 0; i < rows; i++) {
			double* temp = m[i] = new double[cols];
			for (uint32_t j = 0; j < cols; j++)
				m[i][j] = orig.m[i][j];
		}
	}

	Matrix& operator =(const Matrix& orig) {
		Matrix copy(orig);
		rows = orig.rows;
		cols = orig.cols;
		swap(m, copy.m);
		return *this;
	}

	~Matrix() {
		for (uint32_t i = 0; i < rows; i++)
			delete[] m[i];
		delete [] m;
	}
	// MOVE constructor
	Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
		orig.m = nullptr;
	}
	
  double operator()(uint32_t r, uint32_t c) const {
		//		if (r >= rows || c >= cols)
		//			throw BadIndex(__FILE__, __LINE__);
		return m[r][c];
	}
  double& operator()(uint32_t r, uint32_t c) { 
		return m[r][c];
	}
	double* operator [](uint32_t r) {
		return m[r];
	}
	const double* operator [](uint32_t r) const {
		return m[r];
	}
	friend  Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw IllegalSize();
		Matrix ans(a.rows, a.cols);
		for (uint32_t i = 0; i < a.rows; i++)
			for (uint32_t j = 0; j < a.cols; j++)
				ans.m[i][j] = a.m[i][j] + b.m[i][j];
		return ans;
	}

	/*
       a a a     b b     A A
       a a a     b b     A A
       a a a  x  b b =   A A
       a a a             A A
	 */
#if 0
	friend Matrix operator *(const Matrix& a, const Matrix& b) {
		if (a.cols != b.rows)
			throw IllegalSize();
		Matrix ans(a.rows, b.cols, 0.0);
		for (uint32_t i = 0; i < a.rows; i++)
			for (uint32_t j = 0; j < b.cols ; j++)
				for (uint32_t k = 0; k < a.cols; k++)
					ans(i,j) += a(i,k) * b(k,j);
		return ans;
	}
#endif
	
	friend Matrix operator *(const Matrix& a, const Matrix& b) {
		if (a.cols != b.rows)
			throw IllegalSize();
		Matrix ans(a.rows, b.cols, 0.0);
		for (uint32_t i = 0; i < a.rows; i++)
			for (uint32_t j = 0; j < b.cols ; j++) {
				double dot = 0;
				for (uint32_t k = 0; k < a.cols; k++)
					dot += a(i,k) * b(k,j);
				ans(i,j) = dot;
			}
		return ans;
	}
	friend ostream& operator<<(ostream& s, const Matrix& m) {
		for (uint32_t i = 0; i < m.rows; i++) {
			for (uint32_t j = 0; j < m.cols; j++) {
				s << m(i,j) << '\t';
			}
			s << '\n';
		}
		return s;
	}
};


int main() {
  Matrix a(4, 3, 0.0);
	cout << a(2,2);
	a(2,2) = 1.5;
	a[2][1] = 2.5;
	Matrix b(4, 3, 0.0);
	b(1,2) = 1.2;
	b(0,0) = -1.1;
	Matrix c = a + b;
	cout << c << '\n';

	Matrix d(3,2,1.0);   // 4x3   x 3x2 = 4x2 matrix
	Matrix e = a * d;
	cout<< e << '\n';
  b = d;
	cout << d << '\n';
}
