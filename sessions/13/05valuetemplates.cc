#if 0
template<typename Precision>
class Vector {
private:
	Precision x,y,z;

public:
	Vector(Precision x, Precision y, Precision z) : x(x), y(y), z(z) {}
	Vector(const Vector& orig) : x(orig.x), y(orig.y), z(orig.z) {}
	Vector& operator = (const Vector& orig) {
		x = orig.x; y = orig.y; z = orig.z;
		return *this;
	}
	bool operator ==(const Vector& b) {
		return x == b.x && y == b.y ...
	}
	bool operator !=(const Vector& b) {
		return x != b.x || y == b.y e...
	}

};
#endif

template<size_t sz>
class Stack {
private:
	int s[sz];
	int sp;
public:
	Stack() {
		sp = 0;
	}
	void push(int v) {
		s[sp++] = v;
	}
	
	int pop() { }
	bool isEmpty() const { return ___; }

};

int main() {
	Vector<double> a;
	Vector<float> b;
	Vector<int> c;
	Vector<long double> d;

	Vector<double> a2 = a; // copy constructor
  Stack<4096> s;
