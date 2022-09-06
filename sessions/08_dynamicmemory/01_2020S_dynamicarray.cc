#include <iostream>
#include <memory.h>
using namespace std;

class DynamicArray {
private:
	int capacity;
	int size;
	int *p;
	void checkGrow() {
		if ( size >= capacity ) {
			int* old = p; // remember the old memory
			p = new int [ size+size  ];
      for (int i = 0; i < size; i++)
				p[i] = old[i];
			delete [] old;
			capacity = size+size;
		}
	}
public:
	DynamicArray() : capacity(1), size(0), p(new int[1]) {}
	DynamicArray(int initialCapacity) : capacity(initialCapacity), size(0), p(new int[initialCapacity])  {
	}
	~DynamicArray() {
		delete [] p;
	}

	DynamicArray(const DynamicArray& orig) : capacity(orig.capacity), size(orig.size), p(new int[orig.capacity]) {
		//		for (int i = 0; i < orig.size; i++)
		//      p[i] = orig.p[i];
    memcpy(p, orig.p, orig.size * sizeof(int));    		
	}
	// bizarre C++ rule: operator = cannot be a friend
	DynamicArray& operator =(const DynamicArray& orig) {
		if (this !=  &orig ) {
			delete [] p;
			capacity = orig.capacity;
			size = orig.size;
			p = new int[orig.capacity];
			memcpy(p, orig.p, orig.size * sizeof(int));
		}
		return *this;
	}
#if 0
	// copy and swap (another, better way to write the operator =)
	DynamicArray& operator =(DynamicArray copy) {
		capacity = copy.capacity;
		size = copy.size;
		swap(p, copy.p);
		return *this;
	}
#endif

	//move constructor
  DynamicArray(DynamicArray&& orig) : capacity(orig.capacity), size(orig.size), p(orig.p) {
		orig.p = nullptr;
	}
	
	void add(int v) {
		checkGrow();
		p[ size++  ] = v;
	}

	//  inefficient, not great!
	void addStart(int v) {
    checkGrow();
		for (int i = size-1; i >= 0; i--)
			p[i+1] = p[i];
		p[0] = v;
	}
	
	void removeEnd() {
		size--;
	}
	
  friend ostream& operator <<(ostream& s, const DynamicArray& d) {
		for (int i = 0; i < d.size; i++)
			s << d.p[i] << ' ';
		return s;
	}
};

void f(DynamicArray d) {}
DynamicArray g() {
  DynamicArray d(1000);

	return d;
}
int main() {
	DynamicArray a;
	for (int i = 0; i < 100; i++)
		a.add(i);
	cout << a << '\n';
	DynamicArray a2(1000);
	const int n=100000000;
	for (int i = 0; i < n; i++)
		a2.add(i);
	for (int i = 0; i < n; i++)
		a2.removeEnd();
	cout << a2 << '\n';;
	DynamicArray a3(a); //copy constructor
	DynamicArray a4 = a; //copy
	f(a);
	//	for (int i = 0; i < 1000; i++)
	a4 = a2;
	a3 = a4 = a2;
	int x = 2, y = 3, z = 4;
	x = y = z = 0;

	DynamicArray*p = &a2;
	DynamicArray&q = &a2;
	a2 = a2;
	*p = *q;
}
