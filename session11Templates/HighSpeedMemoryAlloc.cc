#include <iostream>
#include <time.h>
using namespace std;

class HighSpeedMemoryAllocator {
private:
	uint32_t size, perBlock;
	char* block;
	uint32_t current;
public:
	HighSpeedMemoryAllocator(uint32_t size, uint32_t perBlock) :
		size(size), perBlock(perBlock) {
    block = new char[size * perBlock];
		current = 0;
	}
	~HighSpeedMemoryAllocator() {
		delete [] block;
	}
  void* alloc() {
		void* temp = block + current;
		current += size;
		return temp;
	}
};


void g() {
	int a = 2;
	int b[1024];
	int c = 3;
	cout << "in function g\n";
	cout << "a=" << &a << '\n';
	cout << "c=" << &c << '\n';
}


void f() {
	int a = 2;
	int b[1024];
	int c = 3;
	cout << "a=" << &a << '\n';
	cout << "c=" << &c << '\n';
	g();
}

void allocateDynamicMemory() {
	constexpr uint32_t N = 10;
	int* a[N];
	for (int i = 0; i < N; i++) {
		a[i] = new int[N]; // 40
		cout << "a[i]=" << a[i] << '\n';
	}
	/*
		new calls malloc

		malloc allocates the size you want + memory containing the size
		in our case, 64 bit computer, they use 8 byte integer to store how big

		+----+
          | 40 |  8 bytes holds the length of the block to come
		      |    |
		p --> +----+
		      | m  |
          | e  |
          | m  |
					+----+

    p = new int[10]; // allocates 40 + 8 bytes

    p++;

    delete [] p;


	*/

	// here is a crash:
	//	*(a[0]-2) = 30;
 
	
	for (int i = 0; i < N; i++)
		delete [] a[i];
}

void fastAlloc(uint32_t numAllocations, uint32_t size) {
	HighSpeedMemoryAllocator a(size, numAllocations);
	char** pointers = new char*[numAllocations];
	for (int i = 0; i < numAllocations; i++)
    pointers[i] = (char*)a.alloc();		
  delete[] pointers;
}

void slowAlloc(uint32_t numAllocations, uint32_t size) {
	char** pointers = new char*[numAllocations];
	for (int i = 0; i < numAllocations; i++)
    pointers[i] = new char[size];

	for (int i = 0; i < numAllocations; i++)
		delete [] pointers[i];
	
  delete[] pointers;
}



int main() {
	int a = 2;
	cout << &a << '\n';
	f();
	allocateDynamicMemory();

	constexpr uint32_t n = 1024*1024, size = 100;
	clock_t t0 = clock();
	fastAlloc(n, size);
	clock_t t1 = clock();
	cout << "FAST: " << (t1-t0) << '\n';


	t0 = clock();
	slowAlloc(n, size);
	t1 = clock();
	cout << "SLOW: " << (t1-t0) << '\n';
}

	
	
