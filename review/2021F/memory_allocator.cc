#include <iostream>
#include <algorithm>

using namespace std;
/*

Write constructor, destructor, copy constructor, operator=
+2 for move constructor
*/
class world {
private:
	uint32_t n;
	int32_t* map;
public:
	world(uint32_t size) : n(size), map(new int32_t[n*n]) {
		for (uint32_t i = 0; i < n*n; i++)
			map[i] = 0;
	}
  ~world() {
    delete [] map;
	}

	world(const world& orig) : n(orig.n), map(new int32_t[orig.n*orig.n])   {
		for (uint32_t i = 0; i < n*n; i++)
			map[i] = orig.map[i];
	}

#if 0
	//you can only write one of the operator =
	//old way of writing operator =
	world& operator =(const world& orig) {
		if (this != &orig) {
			delete [] map;
			n = orig.n;
			map = new int32_t[n*n];
			for (uint32_t i = 0; i < n*n; i++)
				map[i] = orig.map[i];
		}
		return *this;
	}
#endif
	//new way of writing operator = (copy and swap)
	world& operator =(world copy) {
		n = copy.n;
		swap(map, copy.map);
		return *this;
	}
};

void f() {
	world w(100);
}

int main() {
	for (int i = 0; i < 1000000; i++)
		f();

	world a(100);
	world b(20);
	a=b;
	a = a;
}
