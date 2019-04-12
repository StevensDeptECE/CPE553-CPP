class BadSize {
private:
	const char* filename;
	int lineNum;
public:
	BadSize(const char filename[], int lineNum) :
		filename(filename), lineNum(lineNum) {}
	friend ostream& operator <<(ostream& s, const BadSize& b) {
		return s << b.filename << ": " << b.lineNum << " size mismatch";
	}
};

class Matrix {
private:
	int rows, cols;
	double* m;
	static int count;
public:
	Matrix(int rows, int cols, double val);
	static int getCount() {
    return count;
	}
  static Matrix scale(int n, double v) {
		Matrix a(n,n,0);
		for (int i = 0; i < rows*cols; i += rows+1)
			a.m[i] = v;
		return a;
	}
	//https://stackoverflow.com/questions/77005/how-to-automatically-generate-a-stacktrace-when-my-program-crashes
	friend  Matrix operator +(const Matrix& left, const Matrix& right) {
		if (left.rows != right.rows || left.cols != right.cols)
			throw BadSize(__FILE__, __LINE__);
		//		return ...
	}
};

//globally defines the static variable
int Matrix::count = 0;

int main() {
	Matrix m1 = Matrix::identity(4);
	m2(1,3) = 5.5;
	Matrix m2 = m1 * 2.5; // scalar multiplication
	Matrix m3 = m1 + m2;
	cout << m3 << '\n';
	Matrix m4 = m3; // copy constructor
	cout << m4 << '\n';
	cin >> m4;
	// optional: matrix mult 50%
	Matrix m5(2,3, 1.0);
	m5(1,2) = 2.0;
	Matrix m6(3, 4, 2.0);
	m6(2,1) = -1;
	m6(2,3) = -2;
	Matrix m7 = m5 * m6;
	cout << m7 << '\n';	
}
