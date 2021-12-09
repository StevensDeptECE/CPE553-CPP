#ifndef CIRCULARBUFFER_HH_
#define CIRCULARBUFFER_HH_

#include <iostream>
#include <cstdint>

class circularbuffer {
private:
	uint32_t* p;
	uint32_t capacity; // size of the memory block
	uint32_t head, tail;
	void grow();
public:
	// always allocate a power of 2
	circularbuffer(uint32_t capacity);
	~circularbuffer();
  circularbuffer(const circularbuffer& orig);
	// old way
	//	circularbuffer& operator =(const circularbuffer& orig);

	//copy and swap
	circularbuffer& operator =(circularbuffer copy);

	// move constructor
	circularbuffer(circularbuffer&& orig);
	

	void enqueue(uint32_t v);
	uint32_t dequeue();

	bool isEmpty() const;
};

#endif
