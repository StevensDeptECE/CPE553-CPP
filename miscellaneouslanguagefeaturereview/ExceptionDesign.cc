#include "Ex.hh"

class Fraction {

public:
	Fraction(int n, int d) throw (Ex);
};

class Matrix {
public:
	Matrix(uint32_t rows, uint32_t cols) throw(bad_alloc) {
	}

	friend Matrix operator +(const Matrix & a, const Matrix & b) throw(BadSize)
	{
	}

	friend Matrix operator -(const Matrix & a, const Matrix & b) throw(BadSize)
	{
	}

	friend Matrix operator *(const Matrix & a, const Matrix & b) throw(BadSize)
	{
	}
};

