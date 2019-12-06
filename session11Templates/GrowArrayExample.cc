#include <iostream>
#include <memory.h>
using namespace std;

class GrowArray {
private:
	uint32_t len;
	int* data;
public:
	GrowArray() : len(0), data(nullptr) {}
	~GrowArray() { delete [] data; } // ok to delete nullptr
	GrowArray(const GrowArray& orig) : len(orig.len), data(new int[orig.len]) {
		memcpy(data, orig.data, len * sizeof(int));
	}
	GrowArray& operator =(GrowArray orig) {
		len = orig.len;
		swap(data, orig.data);
		return *this;
	}
	GrowArray(GrowArray&& orig) : len (orig.len), data(orig.data) {
		orig.data = nullptr;
	}
	void addEnd(int v) {
		int* old = data;
		data = new int[len +1];
		memcpy(data, old, len* sizeof(int));
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
