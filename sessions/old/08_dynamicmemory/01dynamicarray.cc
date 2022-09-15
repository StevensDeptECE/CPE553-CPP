#include <iostream>
#include <cstdint>
#include <memory.h>
using namespace std;

class DynamicArray {
private:
	uint32_t capacity;
	uint32_t used;
	int* p;
	void checkGrow() {
		if (used >= capacity) {
			capacity *= 2;
			const int* old = p;
			p = new int[capacity];
			for (int i = 0; i < used; i++)
				p[i] = old[i];
			delete [] old;
		} 
	}
public:
  DynamicArray(uint32_t cap = 1) : capacity(cap), used(0), p(new int[capacity])
	{}

	~DynamicArray() {
    delete [] p;
	}
	DynamicArray(const DynamicArray& orig) :
		capacity(orig.capacity), used(orig.used), p(new int[orig.capacity])	{
		memcpy(p, orig.p, orig.used * sizeof(int));
		// memcpy is faster than the fastest loop we can write (I wonder why?)
		//		for (int i = 0; i < used; i++)
		//			p[i] = orig.p[i];	  	
	}

#if 0
	// this is the old solution to writing operator =
	DynamicArray& operator =(const DynamicArray& orig) {
		if (this != &orig) {
			delete [] p;
			capacity = orig.capacity;
			used = orig.used;
			p = new int[orig.capacity];
			memcpy(p, orig.p, orig.used * sizeof(int));
		}
		return *this;
	}
#endif
	
  DynamicArray& operator =(DynamicArray copy) {
		capacity = copy.capacity;
		used = copy.used;
		swap(p, copy.p);
		return *this;
	}

	DynamicArray(DynamicArray&& orig) :
		capacity(orig.capacity), used(orig.used),	p(orig.p) {
		orig.p = nullptr;
	}
	

	void addEnd(int v) {
		checkGrow();
		p[used++] = v;
	}
	void addStart(int v) {
		if (used >= capacity) {
			capacity *= 2;
			const int* old = p;
			p = new int[capacity];
			for (int i = 0; i < used; i++)
				p[i+1] = old[i];
			p[0] = v;
			delete [] old;
			used++;
		}  else {
			for (int i = used-1; i >= 0; i--)
				p[i+1] = p[i];
			p[0] = v;
			used++;
		}
	}
	friend ostream& operator <<(ostream& s, const DynamicArray& d) {
		for (int i = 0; i < d.used; i++)
			s << d.p[i] << ' '; // *(p+i) == p[i]
		return s;
	}
};
/*
	p = new int[5];

  delete [] p;  
  //  p = nullptr;
  p still points to the same memory location! Don't look!


*/



void f(DynamicArray x) {

}

DynamicArray g() {
	DynamicArray temp(3);
	return temp;
}

int main() {
	DynamicArray a; // no elements
	a.addEnd(1);
	for (int i = 0; i < 10; i++)
		a.addEnd(i);

	a.addStart(9);
	cout << a << '\n';

	// all 4 of these cases call the copy constructor
	DynamicArray b = a;
	DynamicArray c(a);
	f(a);
	DynamicArray d = g();
	cout << b << '\n';

	c = d;
	c = c;
	DynamicArray* p1;
	DynamicArray* p2;
	*p1 = *p2;
	int a = 2, b= 3, c = 4;

	a = b = c = 0;


	
}
