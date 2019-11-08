#pragma once
#include <iostream>

template<typename T>
class List { // List$Q_int
private:
	int capacity;
	int used;
	T* data;
	void grow() {}
public:
	List(int initialSize) : capacity(initialSize), used(0), data(new T[capacity* sizeof(T)]) {}
	~List() {
		delete [] data;
	}
  List(const List& orig) : capacity(orig.capacity), used(orig.used), data(new T[capacity]) {
    for (int i = 0; i < used; i++)
			data[i] = orig.data[i];
	}
	List& operator =(const List& orig) {
    List temp = orig;		// same as List temp(orig);
		swap(data, temp.data);
		used = temp.used;
		capacity = temp.capacity;
    return *this;		
	}
	void add(const T& val) {
    grow();
		data[used++] = val;
	}
	friend std::ostream& operator <<(std::ostream& s, const List& list) {
		for (int i = 0; i < list.used; i++)
			s << list.data[i] << ' ';
		return s;
	}
};

#if 0
// if friend is OUTSIDE the class, note you must specify List<T>
template<typename T>
ostream& operator <<(ostream& s, const List<T>& list) {
	for (int i = 0; i < list.used; i++)
		s << list.data[i] << ' ';
	return s;
}

#endif





