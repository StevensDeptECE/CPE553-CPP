#include <iostream>
using namespace std;

class GrowArray {
private:
	int used;
	uint32_t capacity;
	int* data;
	void grow() {
		int* old = data;
		data = new int[capacity = capacity*2+1];
		for (uint32_t i = 0; i < used; ++i)
			data[i] = old[i];
		delete [] old;
	}
public:
	GrowArray(uint32_t initialCapacity = 0)
		: data(new int[capacity]), used(0), capacity(initialCapacity) 
	{}
	~GrowArray() {
		delete [] data;
	}
	GrowArray(const GrowArray& orig) : used(orig.used), capacity(orig.capacity),
																		 data(new int[capacity]){
		for (uint32_t i = 0; i < used; ++i)
			data[i] = orig.data[i];
	}
#if 0
	GrowArray& operator =(const GrowArray& orig) {
		if (this != &orig) {
			delete [] data;
			used = orig.used;
			capacity = orig.capacity;
			data = new int[capacity];
			for (uint32_t i = 0; i < used; ++i)
				data[i] = orig.data[i];
		}
		return *this;
	}
#endif
	// newer copy and swap-style operator  =
	GrowArray& operator =(const GrowArray& orig) {
		GrowArray copy(orig); // make a copy
		swap(copy.data, data);
		used = orig.used;
		capacity = orig.capacity;
		return *this;
	}

	void addEnd(int v) {
		if (used >= capacity)
			grow();
		data [used++] = v;
	}
	/*
   capacity=10
         3     1     4
         v       3     1     4
	 */
  void addStart(int v) {
		if (used >= capacity)
			grow();
		for (uint32_t i = used; i > 0; --i)
			data[i] = data[i-1];
		used++;
		data[0] = v;
	}
	void removeEnd() {
		used--;
	}
	/*
		3    1     4
		1    4
	 */
	void removeStart() {
		//for (uint32_t i = 0; i < used-1; ++i)
		//	data[i] = data[i+1];
		// or, using pointers...
		for (int* p = &data[0]; p < &data[used-1]; ++p)
			*p = *(p+1); // p[0] = p[1];
		used--;
	}
#if 0
	void alternateRemoveStart() {
		data++; // when we delete [] data will crash!!!
		used--;
	}
	#endif
	friend ostream& operator <<(ostream& s, const GrowArray& g) {
		for (int i = 0; i < g.used; i++)
			s << g.data[i] << ' ';
		return s;
	}
};

void f(GrowArray g) { // makes a copy, calls copy constructor

}

GrowArray g() {
	GrowArray a;
	a.addEnd(3);
  return a;
}

int main() {
 	GrowArray a; // empty list, capacity = 0
	GrowArray b(100); // empty list, capacity = 100
	a.addEnd(3);
	a.addStart(1);
	cout << a << '\n';
	GrowArray c = a; // copy constructor
	a.removeEnd();
	a.removeStart();
	cout << a << '\n';
	GrowArray d(b); // copy constructor
	//	c = b;
	//	c = c;
	f(b);
	cout << b << '\n';
}
