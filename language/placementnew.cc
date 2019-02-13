#include <iostream>
#include <memory.h>
using namespace std;


template<typename T>
class List {
private:
	int capacity;
	int used;
	T* data;
	void checkGrow() {
		if (used >= capacity) {
			char* old = (char*)data;
			capacity *= 2;
			data = (T*)new char[sizeof(T) * capacity];
			memcpy(data, old, used * sizeof(T));
			delete [] old;
		}
	}
public:
	List(int initialCap) : capacity(initialCap), used(0), data((T*)new char[sizeof(T)*initialCap]) {}
	void add(const T& e) {
		checkGrow();
		memcpy(data+used, &e, sizeof(T));
		used++;
	}
	~List() {
		for (int i = 0; i < used; i++)
			data[i].~T();
	}
};

class A {
public:
	A() {
		cout << "A()";
	}
	~A() {
		cout << "~A()";
	}
};
		
int main() {
	List<A> list1(5);
	list1.add(A());
	list1.add(A());
	A a1;
	a1.~A(); //manually call destructor? idiocy?
}
