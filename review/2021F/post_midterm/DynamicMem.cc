class A {
private:
	int* p;
	uint32_t capacity;
public:
	A(uint32_t capacity, uint32_t val) : p(new int[capacity]), capacity(capacity) {
    for (uint32_t i = 0; i < capacity; i++)
			p[i] = val;
	}
	~A() {
		delete [] p;
	}
	A(const A& orig) : p(new int[orig.capacity]), capacity(orig.capacity) {
		for (uint32_t i = 0; i < capacity; i++)
			p[i] = orig.p[i];
	}
#if 0
	A& operator =(const A& x) {
		if (this != &x) {
			delete [] p;
			p = new int[x.capacity];
			capacity = x.capacity;
			for (uint32_t i = 0; i < capacity; i++)
				p[i] = x.p[i];
		}
    return *this;		// return the object itself
	}
#endif
	// new way (copy and swap)
	A& operator =(A copy) {
		capacity = copy.capacity;
		swap(p, copy.p);
		return *this;
	}

	A(A&& orig) : p(orig.p), capacity(orig.capacity) {
		orig.p = nullptr;
	}
		
};




	
int main() {
	A a1(100, 5); // a1 should contain pointer to 100 integer elements
	// write : constructor, destructor,  copy constructor operator =

	a1 = a1;
