class A {
private:
	int* p;
public:
	// constructor
	A(uint32_t size) : p(new int[size]) {}

	//destructor
	~A() { delete [] p; }
	//until we get to it, let's not write the copy constructor and operator =
	A(const A& orig) = delete;
	A& operator (const A& orig) = delete;
};

int main() {
	// RAII Resource Allocation Is Initialization
	A a1; // the safe way to allocate memory
	A a2; // when these variables go out of scope, the destructor will automatically deallocate memory
}
