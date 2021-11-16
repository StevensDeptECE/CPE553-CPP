void f() {
	int* p = new int[100];

}

int* g() {
	int* p = new int[100];
	return ;
}

int* h() {
	int p = new int[100];
	delete [] p;
	return p;
}

int* allocarray(int size) {
	int* p = new int[size];
	p[0] = 22;
	p++;
	return p;
}

void freebird(int n) {
	int* p = new int[n];
	free(p);
}

class A {
private:
	uint32_t size;
	int* p;
public:
	A(uint32_t size) : size(size), p(nullptr) {}
	~A() { delete [] p; }
	void print() const {
		for (int i = 0; i < size; i++)
			cout << p[i];
	}
};

class B {
private:
	uint32_t size;
	int* p;
public:
	B(uint32_t size) : size(size) {}
	void print() const {
		for (int i = 0; i < size; i++)
			cout << p[i];
	}
};

class C {
private:
	uint32_t size;
	int* p;
public:
	C(uint32_t size) : size(size) {}
	~C() { delete [] p; }
};


int main() {
	A a1(100);
	a1.print();

	B b1(100);
	b1.print();

	C c1(100);
	
	int*q = g();
	q = h();
	cout << *q << '\n;

	q = h();
	delete [] q;

	q = allocarray(10);
	delete [] q;
}
