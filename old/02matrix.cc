class Matrix {
public:
	Matrix(int rows, int cols) {}
	~Matrix() {}
	Matrix(const Matrix& orig) {}
	Matrix& operator =(const Matrix& orig) {}

	// MOVE constructor
	Matrix(Matrix&& orig) {
		data = orig.data;
		orig.data = nullptr;
		rows = orig.rows;
		cols = orig.cols;
	}
};
int main() {
	Matrix a(3,4);
	Matrix b(3,4);
	Matrix c = a + b;
}
