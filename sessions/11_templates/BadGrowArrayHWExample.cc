#include <iostream>
#include <string>
using namespace std;

template<typename T>
class BadGrowArray {
private:
  uint32_t size;
  char*     data;

public:
  BadGrowArray() : size(0), data(nullptr) {}
  ~BadGrowArray() {
      for (int i = 0; i < size; i++)
        (((T*)data)+i).~T();
      delete [] data;
  }
  BadGrowArray(const BadGrowArray& orig) : size(orig.size), data = new char[orig.size*sizeof(T)] {
      for (int i = 0; i < size; i++)
        new (((T*)data) + i) T(((T*)orig.data)[i])
  }
  void* operator new(size_t sz, void* p) {
    return p;
  }
  void addEnd(const T& v) {
     const char* old = data;
     data = new char[(size+1)*sizeof(T)];
     memcpy(data, old, size*sizeof(T));
     new (data+size) T(v); // call copy constructor placing object at data[size]
     size++;
     delete [] old;
  }
  void removeEnd() {
     const char* old = data;
     size--;
     data = new char[size*sizeof(T)];
     memcpy(data, old, size*sizeof(T));
     delete [] old;
  }
  friend ostream& operator <<(ostream& s, const BadGrowArray& list) {
      for (int i = 0; i < list.size; i++)
        s << ((T*)list.data)[i] << ' ';
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
#if 0	
	BadGrowArray<string> b;
	b.addEnd("hello");
	string s[] = { "test", "this", "now" };
	
	for (int i = 0; i < sizeof(s)/sizeof(string); i++)
		b.addEnd(s[i]);
	b.removeEnd();
	cout << b << '\n';
#endif

	GrowArray<string> c = b; // test copy constructor
	c.removeEnd();
	c = b; // test operator =
}
