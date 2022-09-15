#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

class Elephant {
	friend ostream& operator <<(ostream& s, const Elephant& e) {
		return s << "Yo, I'm an elephant.";
	}
};

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
		//		for (int i = 0; i < len; i++)
		//			data[i] = old[i];
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
	// NOTE: STUPID C++ RULE: some operators cannot be made friends
	// must be members: operator =, [], ()
	// 
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
	GrowArray<int> a;
	a.add(5);
	a.add(6);
	for (int i = 0; i < 10; i++)
		a.add(i);
	a[4] = 22;
	cout << a << '\n';
	cout << a[4] << '\n';
	
	GrowArray<int> b;
	GrowArray<int> c;
	c.add(2);
	b = c = a;

	GrowArray<string> d;
	d.add("hello");
	d.add("bye");
	cout << d << '\n';

	
	GrowArray<Elephant> elephants;
	elephants.add(Elephant());
	elephants.add(Elephant());
	cout << elephants;
}
