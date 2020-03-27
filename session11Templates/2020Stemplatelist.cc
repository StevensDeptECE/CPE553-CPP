#include <iostream>
using namespace std;

template<typename T>
class List {
private:
  int capacity;
	T* data;
public:
  List() : capacity(0), data(nullptr) {}
	~List() {
		delete [] data;
	}

	List(const List& orig) : capacity(orig.capacity), data(new T[orig.capacity]) {
		memcpy(data, orig.data, capacity*sizeof(T));
	}

	//old way of disabling operator =: 	List& operator =(List copy);
	//new way of disabling operator =: 	List& operator =(List copy) = delete;
	List& operator =(List copy) {
		capacity = copy.capacity;
		swap(data, copy.data);
		return *this;
	}
	
	void add(const T& v) {
		T* old = data;
		data = new T[capacity+1]; // your object must contain constructor T()
    for (int i = 0; i < capacity; i++)
			data[i] = old[i];
		data[capacity++] = v; 
    delete [] old;
	}
	friend ostream& operator <<(ostream& s, const List& list) {
		for (int i = 0; i < list.capacity; i++) {
			s << list.data[i] << ' ';
		}
		return s;
	}
};

int main() {
	List<int> a;
	for (int i = 0; i < 10; i++)
		a.add(i);
	cout << a << '\n';
	
	List<float> b;
	for (int i = 0; i < 10; i++)
		b.add(i+0.5);
	cout << b << '\n';


}
