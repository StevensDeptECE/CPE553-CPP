class Vector {
private:
	int n;
	int* p;
public:
	Vector(int n) : p(new int[n]), n(n) {
		for (int i = 0; i < n; i++)
			p[i] = n;
	}

	Vector() : p(nullptr) {}
	
	~Vector() {
		delete [] p;
	}

	Vector(const Vector& orig) :  n(orig.n), p(new int[orig.n]) {
		for (int i = 0; i < n; i++)
			p[i] = n;
	}
	
  Vector& operator =(Vector copy) { // copy is passed by value
    n = copy.n; // copy
		swap(p, copy.p); // and swap
	}

  Vector(Vector&& orig) : n(orig.n), p(orig.p) {
		orig.p = nullptr;
	}
	
};

Vector f() {
	return Vector(19);
}


int main() {
	Vector v1(5);
	Vector v2;

	Vector v3 = v1; // error, copy constructor is unimplemented

	Vector v4 = v1;

	v4 = v2;

}
