class A {
private:
	int* a;
	int* b;
public:
	A(int m, int n) {
		if (m < 0)
			throw "bad size";
		a = new int[m];
		if (n < 0) { // better to do this all at the start
			delete [] a; // undo what you have already allocated
			throw "bad size";
		}
		b = new int[n];
	}

	~A() {
		delete [] a;
		delete [] b;
	}
};

int main() {
	try {
		A a1(3,4); // Resource allocation Is Initialization (RAII)


	} catch(const char* ex) {
		cout << ex << '\n';
	}
}
		
