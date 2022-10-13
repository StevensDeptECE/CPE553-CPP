class A {
private:
	int* p;
public:
	A(uint32_t size) : p(new int[size]) {}

	~A() { delete [] p; }
};

int main() {
	A a1; // the safe way to allocate memory
	A a2; // when these variables go out of scope, the destructor will automatically deallocate memory
}
