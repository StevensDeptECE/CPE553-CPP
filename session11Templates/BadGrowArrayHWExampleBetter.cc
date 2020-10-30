#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

template<typename T>
class BadGrowArray {
private:
  uint32_t size;
  T*       data;
public:
  BadGrowArray() : size(0), data(nullptr) {}
  ~BadGrowArray() {
      for (uint32_t i = 0; i < size ;i++)
        data[i].~T();
      delete [] (char*)data;
  }
  BadGrowArray(const BadGrowArray& orig) : size(orig.size), data((T*)new char[orig.size*sizeof(T)]) {
      for (int i = 0; i < size; i++)
        new (data + i) T(orig.data[i]);
  }
  BadGrowArray& operator =(BadGrowArray copy) {
    size = copy.size;
    swap(data, copy.data);
    return *this;
  }
  void* operator new(size_t sz, void* p) {
    return p;
  }
  void addEnd(const T& v) {
     char* old = (char*)data;
     data = (T*)new char[(size+1)*sizeof(T)];
     memcpy(data, old, size*sizeof(T));
     new (data+size) T(v); // call copy constructor placing object at data[size]
     memset(old, 0, size*sizeof(T));
     size++;
     delete [] (char*)old;
  }
  void removeEnd() {
     const char* old = (char*)data;
     size--;
     data[size].~T();
     data = (T*)new char[size*sizeof(T)];
     memcpy(data, old, size*sizeof(T));
     delete [] (char*)old;
  }
  friend ostream& operator <<(ostream& s, const BadGrowArray& list) {
      for (int i = 0; i < list.size; i++)
        s << list.data[i] << ' ';
      return s;
  }
};
class Elephant {
    private:
        string name;
    public:
        Elephant() : name("Fred") {}
        Elephant(const string& name) {}
};
int main() {
	BadGrowArray<int> a;
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	for (int i = 0; i < 9; i++)
		a.removeEnd();
	// should have 0
	cout << a << '\n';

	BadGrowArray<string> b;
	b.addEnd("hello");
	string s[] = { "test", "this", "now" };
	
	for (int i = 0; i < sizeof(s)/sizeof(string); i++)
		b.addEnd(s[i]);
	b.removeEnd();
	cout << b << '\n';

	BadGrowArray<string> c = b; // test copy constructor
	c.removeEnd();
	c = b; // test operator =
}
