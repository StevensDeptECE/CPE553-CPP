class Matrix {
public:
	Matrix() {}
};

Matrix f1() {
	return Matrix();
}

Matrix f2() {
	Matrix ans;
	return ans;
}

Matrix& f3() {
	return Matrix(); // illegal, the reference points to something that won't exist
}

Matrix& f4() {
	Matrix ans;
	return ans; // illegal, the reference points to something that won't exist
}

Matrix* f5() {
	Matrix ans;
	return &ans; // illegal, the pointer points to something that won't exist
}


int main() {
	int a;

	cout << &a; // what is the address of a?
	cout << *a; // error, a is not a pointer
}

