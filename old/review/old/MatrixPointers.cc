#include <iostream>
using namespace std;

class Matrix {

public:
	static Matrix identity(int size) {
		Matrix ans(size,size);

		return ans;
	}
};


int main() {
	Matrix m1(10); // 10x10 matrix all zeros. Use pointers to set zeros
  Matrix m2(m1); //copy constructor
	Matrix m3 = m1; // copy
	m1 = Matrix::identity(3);
	// 1 0 0 
	// 0 1 0
	// 0 0 1
  cout << m1;
}
