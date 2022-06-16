#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

class matrix {
private:
  double* p;
	uint32_t rows, cols;
public:
  matrix(uint32_t rows, uint32_t cols, double defaultVal = 0.0)
		: p(new double[rows*cols]), rows(rows), cols(cols) {
		for (int i = 0; i < rows * cols; i++)
			p[i] = defaultVal;
	}
	double   operator ()(uint32_t r, uint32_t c) const {
    return p[r * cols + c];
	}
	double&   operator ()(uint32_t r, uint32_t c) {
    return p[r * cols + c];
	}

	friend ostream&  operator <<(ostream& s, const matrix& m) {
		for (uint32_t i = 0; i < m.rows; i++) {
			for (uint32_t j = 0; j < m.cols; j++)
				s << m(i,j) << ' ';
			s << '\n';
		}
		return s;
	}

	friend istream& operator >>(istream& s, matrix& m) {
		for (int i = 0; i < m.rows * m.cols; i++)
			s >> m.p[i];
		return s;
	}
	
};

int main() {
	/*
		1.2  2  3   4
    2  3  4   5
    3  3  -1  2
	 */


	matrix a(3, 4, 0.0);
	cout << a(1,1) << '\n';
	
	a(1,1) = 3;
	cout << a << '\n';
	
	ifstream f("mat.dat");
	f >> a;
	cout << a << '\n';
}
