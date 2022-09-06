#include <iostream>
/*
	this code shows how to use placement new, which is important for efficient
	classes copying data of type T

	new Elephant; --> 

  void* operator new(size_t sz) {
    return malloc(sz);
  }

  new (where to put it) Elephant;

*/
template<typename T>
class Test {
private:
	T* data;
	uint32_t len;
	void* operator new(size_t sz, T* place) {
		return place;
	}

public:
	Test(uint32_t capacity) : len(0), data((T*)new char[capacity * sizeof(T)]) {}
	~Test() {
		for (int i = 0; i < len;  i++)
			data[i].~T();
		delete [] (char*)data;
	}
	void set1() {
		new (&data[0]) T();
		len = 1;
	}
	
};

int main() {
  Test t1(1000);
	t1.set1(); // set first element
}	
	
