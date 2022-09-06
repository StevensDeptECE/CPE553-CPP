class B;
struct A {
	int x;
	char c;
	uint64_t a;
	float b;
	double d;
	B* p;
};

/* 
memory layout of A
  x x x x c ? ? ?
  a a a a a a a a
  b b b b ? ? ? ?
  d d d d d d d d
  p p p p p p p p
*/

class B;

class B {
private:
	int x;
	void f();
	void g() { cout << "write it inline"; }
  B() {}
protected: // only for children
	int y;
	void h();
public:
  B(int x) : x(x) {}
};

// a class is a definition. You can declare something many times. You can only define it once

int a = ~3; // 3=00000000000000011 ~3=11111111111111111111100

class C {
public:
	static int count; // turns into extern int count;

	static int getCount() { return count; }
	C() { count++; cout << "yo" << getCout(); }
	~C() { count--; cout << "ho" << getCout(); }
};

int C::count = 0; // someone defines the variable

int main() {
	C a,b,c; // what gets printed here? yo1yo2yo3ho2ho1ho0
}

class Fred;

class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d) : num(n), den(d) {}
	Fraction operator +(const Fraction& r) const;
	Fraction operator -() const {
		return Fraction(-num,den);
	}

	friend Fraction operator -(const Fraction& a, const Fraction& b) {
		return Fraction(a.num*b.den + a.den*b.num, a.den*b.den);
	}
	friend Fraction operator +(const Fraction& a) {
		return Fraction(a.num,a.den);
	}
private: // private means nothing for friendship. A friend is a friend.
	friend Fred; // any method of Fred is ok!
};

Fraction Fraction::operator +(const Fraction& r) const {
	return Fraction(num*r.den + den*r.num, den*r.den);
}
class Fred {
public:
	void f() {
		Fraction a(1,2);
		a.num = 19;

	}
};


class Chunk {
private:
	int len;
	int* p;
public:
	void set(int i, int val) {
		p[i] = val;
	}
	Chunk(int n, int val) : len(n), p(new int[n]) {
		for (int i = 0; i < len; i++)
			p[i] = val;
	}
	~Chunk() {
		delete [] p;
	}
	Chunk(const Chunk& orig) : len(orig.len), p(new int[orig.len]) {
		for (int i = 0; i < len; i++)
			p[i] = orig.p[i]; // in object-oriented programming, secrecy is from OTHER KINDS OF OBJECTS
	}
	Chunk& operator =(Chunk orig) {
    len = orig.len;
		swap(p, orig.p);
		return *this;
	}
	Chunk(Chunk&& orig) len (orig.len), p(orig.p) {
		orig.p = nullptr;
	}
};

Chunk f() {
	return Chunk (43,4);
}

int main() {
	Chunk a(100, 5); //allocate 100 elements, set each one to 5
	Chunk b(a); // make a copy
	Chunk c = a; // make a copy
	c.set(3, 19);
	b = c; // operator =: delete memory in b, then copy c
}


int bitops() {
	int a = 3 << 4;
	int b = 4 >> 1;
	int c = 3 & 4; //AND
	int d = 3 | 4;// oR
	int e = 3 ^ 4; //XOR
	int f = ~4; // NOT
}


template<typename T>
void sort(T x[], int len) {

	//	if (x[i] > x[i+1])
}


//sort(elephants, &Elephant::name);

Complex<double> a(2.5, 3.2);
Complex<float> b(1.5f, 2.0f);

template<typename Precision>
class Complex {
private:
	Precision r, i;
public:
	Complex(Precision r, Precision i) : r(r), i(i) {}
	friend Complex  operator +(Complex a, Complex b) {
		return Complex(a.r+b.r, a.i+b.i);
	}
};


/*

regex
Variadic templates
lambda functions
Functors
operator ()
	operator []
operator ->
private, protected inheritance
	virtual inheritance

*/
