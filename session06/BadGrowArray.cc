#include <iostream>
using namespace std;

class BadGrowArray {
private:	
  int* p;
	uint32_t len;
public:
	BadGrowArray() : p(nullptr), len(0) {}
	~BadGrowArray() {
		delete [] p;
	}
	BadGrowArray(const BadGrowArray& orig) : p(new int[orig.len]), len(orig.len) {
		for (int i = 0; i < len; i++)
			p[i] = orig.p[i];
	}

	#if 0
	// old way of writing operator =
	BadGrowArray&  operator =(const BadGrowArray& orig) {
		if (this != &orig) {
			delete [] p;
			p = new int [ orig.len ];
			len = orig.len;
			for (int i = 0; i < len; i++)
				p[i] = orig.p[i];
		}
		return *this;
	}
#endif
	// new copy and swap paradigm
	BadGrowArray& operator =(BadGrowArray copy) {
    swap(p, copy.p);
		len = copy.len;
		return *this;
	}
	
  void addEnd(int v) {
		const int* old = p;
    p = new int[len+1];
		for (int i = 0; i < len; i++)
			p[i] = old[i];
		delete [] old;
		p[len++] = v; // len = 3
	}
	friend ostream& operator <<(ostream& s, const BadGrowArray& list) {
		for (int i = 0; i < list.len; i++)
			s << list.p[i] << ' ';
		return s;
	}
};


int main() {
	int x = 2;
  BadGrowArray a; // calls what?
	for (int i = 0; i < 10; i++)
		a.addEnd(i); // 0 1 2 3 4 5 6 7 8 9
	cout << a;

	BadGrowArray b = a;
	b.addEnd(5);
	a.addEnd(6);

	BadGrowArray b2(a);

	BadGrowArray c;
	c.addEnd(3);
	b = c; // operator =

	b = b; // pathological case, but we cannot avoid it

	//		BadGrowArray *p = ...
	//	BadGrowArray * q = ...
	//	*p = *q;


	
}
