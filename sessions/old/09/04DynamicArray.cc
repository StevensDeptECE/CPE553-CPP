#include <iostream>
using namespace std;

class DynamicArray  { 
private:
	int* p;
	int size_;
public:
  DynamicArray() : p(nullptr), size_(0) {}
#if 0
	DynamicArray(const DynamicArray& orig) : size_(orig.size_)
	{
		p = new int[size_];
		for (int i = 0; i < size_; i++)
			p[i] = orig.p[i];
	}
#endif
	
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

void f() {
	DynamicArray a;
	a.addEnd(3);
	a.addEnd(1);
	a.addEnd(4);
	a.addEnd(1);
	DynamicArray b = a; // DynamicArray(const DynamicArray&orig)
	cout << a << '\n';
	cout << b << '\n';
	b.addEnd(5);
	cout << "after adding a 5 to b\n";
	cout << a << '\n';
	cout << b << '\n';
	cout << endl;
}

int main() {
	f();
}
