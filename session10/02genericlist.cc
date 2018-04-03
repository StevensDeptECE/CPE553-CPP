#include <iostream>
using namespace std;

template<typename T>
class GrowArray {
private:
	int used;
	uint32_t capacity;
	T* data;
	void grow() {
		T* old = data;
		data = new T[capacity = capacity*2+1];
		for (uint32_t i = 0; i < used; ++i)
			data[i] = old[i];
		delete [] old;
	}
public:
	GrowArray(uint32_t initialCapacity = 0)
		: data(new T[capacity]), used(0), capacity(initialCapacity) 
	{}
	~GrowArray() {
		delete [] data;
	}
	GrowArray(const GrowArray& orig) : used(orig.used), capacity(orig.capacity),
																		 data(new T[capacity]){
		for (uint32_t i = 0; i < used; ++i)
			data[i] = orig.data[i];
	}
	// newer copy and swap-style operator  =
	GrowArray& operator =(const GrowArray& orig) {
		GrowArray copy(orig); // make a copy
		swap(copy.data, data);
		used = orig.used;
		capacity = orig.capacity;
		return *this;
	}

	void addEnd(const T& v) {
		if (used >= capacity)
			grow();
		data [used++] = v;
	}
	void removeEnd() {
		used--;
	}
	friend ostream& operator <<(ostream& s, const GrowArray& g) {
		for (int i = 0; i < g.used; i++)
			s << g.data[i] << ' ';
		return s;
	}
};

int main() {
 	GrowArray<int> a; // empty list of int, capacity = 0
	GrowArray<double> b(100); // empty list, capacity = 100
	a.addEnd(3);
	b.addEnd(2.5);
	cout << a << '\n';
	cout << b << '\n';
}
