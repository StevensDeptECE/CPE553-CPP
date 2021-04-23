#include <iostream>
#include <string>
using namespace std;

template<typename T>
class BadGrowArray {
private:
	uint32_t len;
	char* data;
	void* operator new(size_t sz, T* place) {
		return place;
	}
  T* get(int i) const {
		return ((T*)data) + i;
	}
public:
	BadGrowArray() : len(0), data(nullptr) {}
	~BadGrowArray() {
		delete [] data;
	}
	BadGrowArray(const BadGrowArray& orig) : len(orig.len), data(new char[len*sizeof(T)]) {
		for (int i = 0; i < len; i++) {
			new ( get(i) ) T( ((T*)orig.data) [i]);
		}
	}
	
	BadGrowArray& operator =(BadGrowArray copy)  {
		len = copy.len;
		swap(data, copy.data);
		return *this;
	}
	
  void add(const T& v) {
		const	T* old = (T*)data;
		data = new char[(len+1)*sizeof(T)]; // calls constructor len+1 times
		for (int i = 0; i < len; i++)
			new ( get(i) ) T( std::move(old[i])); // placement new. Create a copy of T ( ) from old[i] and put in data[i]
		((T*)data)[len++] = v;
	}

	friend ostream& operator <<(ostream& s, const BadGrowArray& list) {
		for (int i = 0; i < list.len; i++)
			s << *list.get(i) << ' ';
		return s << '\n';
	}
};

int main() { 
	BadGrowArray<float> a;
	for (int i = 0; i < 10; i++)
		a.add(i);
	cout << a << '\n';
	
	BadGrowArray<string> b;
	for (int i = 0; i < 10; i++)
		b.add("test");
	cout << b << '\n';

	BadGrowArray<string> c(b);
}
