#include <iostream>
#include <memory.h>
using namespace std;

class GrowArray {
private:
	uint32_t capacity;
	uint32_t len;
	int* data;
	void checkGrow() {
		if (len < capacity)
			return;
		const int* old = data;
		data = new int[capacity*2];
		memcpy(data, old, len * sizeof(int));
		delete [] old;
		capacity = 2*capacity;
	}
public:
	GrowArray(uint32_t capacity) : capacity(capacity), len(0), data(nullptr) {}
	~GrowArray() { delete [] data; } // ok to delete nullptr
	GrowArray(const GrowArray& orig) :
		capacity(orig.capacity), len(orig.len), data(new int[orig.capacity]) {
		memcpy(data, orig.data, len * sizeof(int));
	}
	GrowArray& operator =(GrowArray orig) {
		capacity = orig.capacity;
		len = orig.len;
		swap(data, orig.data);
		return *this;
	}
	GrowArray(GrowArray&& orig)
		: capacity(orig.capacity), len(orig.len), data(orig.data) {
		orig.data = nullptr;
	}
	
	void addEnd(int v) {
		checkGrow();
		data[len++] = v;
	}
	
	class Iterator {
	private:
		int* current;
		int remaining;
	public:
    Iterator(GrowArray& a) : current(a.data), remaining(a.len) {
		}
    bool operator !() const {
			return remaining != 0;
		}

		void operator ++() {
			current++;
			remaining--;
		}
		int& operator *() const {
			return *current;
		}
		
	};
  friend Iterator;	

};



int main() {
	int*p = nullptr;
	delete p; // LEGAL!!!

	GrowArray a;
	for (int i = 0; i < 10; i++)
		a.addEnd(i);

	for (GrowArray::Iterator i = a; !i; ++i)
		*i *= 2;

	for (GrowArray::Iterator i = a; !i; ++i)
		cout << *i;

	//cout << a;
}
