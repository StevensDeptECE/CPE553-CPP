#include <iostream>
using namespace std;

class DynamicArray {
private:
  int* p;
	int size;
public:
	DynamicArray() : p(nullptr), size(0) {}
	void add(int v) {
		int* temp = p;
		p = new int[size+1];
		for (int i = 0; i < size; i++)
			p[i] = temp[i];
		p[size++] = v;
		delete [] temp;
	}

	~DynamicArray() {
		delete [] p;
	}

	DynamicArray(const DynamicArray& orig) :  size(orig.size) {
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = orig.p[i];
	}
	DynamicArray& operator =(DynamicArray copy) {
		size = copy.size;
		swap(p, copy.p);
		return *this;
	}

	friend ostream& operator <<(ostream& s, const DynamicArray& d) {
		for (int i = 0; i < d.size; i++)
			s << d.p[i] << ' ';
		return s;
	}
};

int main() {
	DynamicArray a;
	for (int i = 0; i < 100; i++)
		a.add(i);
	cout << a << '\n';
	DynamicArray b = a; // call copy constructor
	DynamicArray c(a); // call copy constructor



	
}
