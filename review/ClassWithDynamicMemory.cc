class A {
private:
	int* p;
public:
	A() {
		p = new int[4];
		for (int i = 0; i < 4; i++)
			p[i] = 0;
	}
	// this default copy constructor is WRONG:	A(const A&orig) : p(orig.p) {}
  A(const A& orig) : p(new int[4]) {
		for (int i = 0; i < 4; i++)
			p[i] = orig.p[i];
	}
	A& operator =(const A& orig) {
		if (this != &orig) {
			delete [] p;
			p = new int[4];
			for (int i = 0; i < 4; i++)
				p[i] = orig.p[i];
		}
		return *this;
	}

	
  ~A() { delete [] p; }
	int& operator [](int i) { return p[i]; }
};

class B {
private:
	int x,y;
public:
	B(int x, int y) :x(x), y(y) {}
	//default copy constructor
	B(const B& orig) : x(orig.x), y(orig.y) {}
};

int main() {
	A a1;
	a1[2] = 99; // 0 0 99 0

	A a2;
	a2[1] = 88; // 0 88 0 0
	A a3 = a2; // 5 88 0 0
	a3[0] = 5;
	a1 = a3; // deallocate memory I have, allocate new memory, copy the orig
  a1 = a1 = a3;
	
	B b1(2,3);
	B b2 = b1;
