#include <iostream>
using namespace std;

class List {
private:
	int used;
	int capacity;
	int* list;
	void checkGrow() {
		if (used < capacity)
			return;
		int* old = list;
		if (capacity == 0)
			capacity = 1;
		list = new int[capacity*2];
    for (int i = 0; i < capacity; i++)
			list[i] = old[i];
		delete [] old;
	}
public:
	List(int initialSize) : used(0), capacity(initialSize), list(new int[capacity])	{}
	List() : List(1) {}
	void add(int v) {
		checkGrow();
		list[used++] = v;
	}
  ~List()	{
		delete [] list;
	}
  List(const List& orig) : used(orig.used), capacity(orig.capacity), list(new int[capacity]) {
		for (int i = 0; i < used; i++)
			list[i] = orig.list[i];
	}
#if 0
	List& operator =(const List& orig) {
		if (this != &orig) {
			delete [] list;
			used = orig.used;
			capacity = orig.capacity;
			list = new int[capacity];
			for (int i = 0; i < used; i++)
				list[i] = orig.list[i];
		}
		return *this;
	}
#endif
	//copy and swap (the "new" c++11 way)
	List& operator =(List copy) {
		used = copy.used;
		capacity = copy.capacity;
		swap(list, copy.list);
		return *this;
	}

	List(List&& orig) : used(orig.used), capacity(orig.capacity), list(orig.list) {
		orig.list = nullptr;
	}
};

List buildList(int a, int b) {
	List ans(b-a+1);
	for (int i = a; i <= b; i++)
		ans.add(i);
	return ans;
}


int main() {
	int x = 0; //declaration with initialization
	x = 2; // assignment

	
	List a(20);
	List b(30);
	a.add(5);
	b.add(3);
	List c = a; // COPY CONSTRUCTOR
	b = a;
  c = c;

	a = b = c;
	a = a;
}
