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
		//		memcpy(p, orig.p, rows*cols*sizeof(double));
		for (int i = 0; i < rows*cols; i++)
			m[i] = orig.m[i];
	}
	void operator =(const Matrix& orig) {
		if (this != &orig) {
			delete [] m;
			rows = orig.rows;
			cols = orig.cols;
			m = new double[rows*cols];
			for (int i = 0; i < rows*cols; i++)
				m[i] = orig.m[i];
		}
	}

};

void f(Matrix m) {

}

Matrix g() {
	return Matrix(3,3);
}

int main(){
	Matrix a(4,3); // create 4x3 matrix all zero

	/*
		0 0 0
		0 0 0
		0 0 0
		0 0 0
	*/
	
	Matrix b(4,3, 1.0);
	/*
		1 1 1
		1 1 1
		1 1 1
		1 1 1
	*/
	//	int x = 2; // initialization
	//	int y= x;
	//  y = 4; // assignment

	Matrix copy = b; // this calls the copy constructor
	Matrix copy2(b);// this also calls the copy constructor
  f(b); // so does passing a parameter by value!
	Matrix m = g(); // so does returning a value!

	Matrix c(2,2,3.5);
	/*
		3.5 3.5
		3.5 3.5
	*/

	int w = 2;
	w = w;
	a = c; // copy all the values from b to a
	
	Matrix c = a + b;
	cout << c;
}
