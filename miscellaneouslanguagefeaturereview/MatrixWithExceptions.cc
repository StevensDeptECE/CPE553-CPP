#include <iostream>
using namespace std;

class Matrix {
private:
	uint32_t rows, cols;
	double* m;
public:
	Matrix(int rows, int cols) {
		if (rows < 0 || cols < 0)
			throw "bad size";
		this->rows = rows;
		this->cols = cols;
		m = new double[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			m[i] = 0;
	}
  ~Matrix() {
		delete [] m;
	}
	//copy constructor
	Matrix(const Matrix& orig) = delete;

	//move constructor
	Matrix(const Matrix&& orig) = delete;

	Matrix& operator =(const Matrix& orig) {

		return *this;
	}

  friend Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols) {
			throw "bad size";
		}
		Matrix ans(a.rows, a.cols);
		for (int i = 0; i < a.rows*a.cols; i++)
			ans.m[i] = a.m[i] + b.m[i];
		return ans;
	}
};

// if no catch is found, program calls terminate() --> abort()
int main() {
	try {
		Matrix a(3,4);
		Matrix b(4,3);
		Matrix c = a + b;
	} catch(const char* msg) {
		cout << msg << '\n';
	}
}
