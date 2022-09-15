#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
template<typename T>
class GrowArray {
private:
	int capacity;
	int len;
	T* data;
	// this function should double the size of the block and be called whenever add
	// has no more room
	void grow() {

	}
public:
	GrowArray()  {

	}
	GrowArray(int initialCapacity) : capacity(initialCapacity), data() {
		
	}
	~GrowArray() {

	}
	GrowArray(const GrowArray& orig) {




	}
	GrowArray& operator =(const GrowArray& orig) {



		return *this;
	}
  GrowArray(GrowArray&& orig) {




	}
	
	void add(const T& v) {








	}
	friend ostream& operator <<(ostream& s, const GrowArray& a) {
		for (int i = 0; i < a.len; i++)
			s << a.data[i] << ' ';
		return s;
	}
	T operator [](int i) const {
		if (i >= len)
			throw "Index out of bounds";
		return data[i];
	}

	T& operator [](int i) {
		if (i >= len)
			throw "Index out of bounds";
		return data[i];
	}
};

int main() {
	GrowArray<int> a(10);
	for (int i = 0; i < 10; i++)
		a.add(i);
	cout << a << '\n';
}
