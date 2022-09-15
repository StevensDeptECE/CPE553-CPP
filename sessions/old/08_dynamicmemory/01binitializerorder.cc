#include <cstdint>

class A {
private:
	int* p;  // p is initialized First because it is first in memory
	uint64_t size;
public:
	//	A(uint32_t sz) : size(sz), p(new int[sz]) {} // initializer order does not count
	A(uint32_t sz) : size(sz), p(new int[size]) {} // this will crash because size is undefined when new int[size] happens

	// this would be recommended
	//	A(uint32_t sz) : p(new int[sz]), size(sz) {} 

};

int main() {
	A a1(3);
}
