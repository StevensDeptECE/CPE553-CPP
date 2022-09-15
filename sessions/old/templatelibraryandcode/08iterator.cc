#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

template<typename T>
class GrowArray {
private:
	int len;
	T* data;
public:
	GrowArray() : data(nullptr), len(0) {}
	~GrowArray() { delete[] data; }
	GrowArray(const GrowArray& orig) : len(orig.len), data(new T[len]) {
		for (int i = 0; i < len; i++)
			data[i] = orig.data[i];
	}
	GrowArray& operator =(const GrowArray& orig) {
		GrowArray copy(orig);
		this->len = orig.len;
		swap(this->data, copy.data); // swap so the temporary copy dies and deletes the old memory
		return *this;
	}
  GrowArray(GrowArray&& orig) : len(orig.len), data(orig.data) {
		orig.data = nullptr;
	}
	
	void add(const T& v) {
		T* old = data;
		data = new T[len+1];
		for (int i = 0; i < len; i++)
			data[i] = old[i];
		data[len] = v;
		delete [] old;
		len++;
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
	class Iterator {
	private:
		GrowArray<T>& list;
		int current;
	public:
		Iterator(GrowArray& list) : list(list), current (0) {
		}
		bool operator !() const {
			return current < list.len;
		}
		void operator ++() {
			current++;
		}
		T& operator*() {
			return list.data[current];
		}
	};
};

int main() {
	GrowArray<int> a;
	for (int i = 0; i < 10; i++)
		a.add(i);
	cout << a << '\n';
	// note:GrowArray<int>::Iterator i = a is a constructor, not operator =
	for (GrowArray<int>::Iterator i = a; !i; ++i)
		*i *= 2;
	cout << a << '\n';
}


