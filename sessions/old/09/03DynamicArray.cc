#include <iostream>
using namespace std;

class DynamicArray  { 
private:
	int* p;
	int size_;
public:
  DynamicArray() : p(nullptr), size_(0) {}
	~DynamicArray() {
		delete [] p;
	}
	int size() const { return size_; }
	void addEnd(int v) {
		int* old = p;
		p = new int[size_+1];
		for (int i = 0; i < size_; i++)
			p[i] = old[i];
		p[size_] = v;
		delete [] old;
		size_++;
	}
	friend ostream& operator <<(ostream& s, const DynamicArray& a) {
		for (int i = 0; i < a.size(); i++)
			s << a.p[i] << ' ';
		return s;
	}
};

int main() {
	DynamicArray a;
	a.addEnd(3);
	a.addEnd(1);
	a.addEnd(4);
	a.addEnd(1);
	cout << a << '\n';
}
