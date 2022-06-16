#include "circularbuffer.hh"
#include <utility>
using namespace std;

/*
     0  1  2  3  4  5  6  7  8  9
 p->[7  5  9  12 49 61            ]
        h
           t                           

 */

circularbuffer::circularbuffer(uint32_t capacity) :
	p(new uint32_t[capacity]), capacity(capacity-1), head(0), tail(0) {
}

// 10000000 00000000 00000000 00000000
// 10000000 00000000 10000000 00000000
// 10000000 10000000 10000000 10000000
// 10001000 10001000 10001000 10001000
// 10101010 10101010 10101010 10101010
// 11111111 11111111 11111111 11111111


uint32_t power2m1(uint32_t v) {
	v = v | (v >> 16);
	v = v | (v >> 8);
	v = v | (v >> 4);
	v = v | (v >> 2);
	return v | (v >> 1);
}		


circularbuffer::~circularbuffer() {
  delete [] p;
}

circularbuffer::circularbuffer(const circularbuffer& orig)
	: p(new uint32_t[orig.capacity+1]), capacity(orig.capacity),
		head(orig.head), tail(orig.tail) {
	if (head < tail) {
		for (uint32_t i = head; i<tail; i++)
			p[i] = orig.p[i];
	} else if (head == tail){
		// copy nothing, the queue is empty
	} else {
		for (uint32_t i = head; i <= capacity; i++)
			p[i] = orig.p[i];
		for (uint32_t i = 0; i < tail; i++)
			p[i] = orig.p[i];
	}
}

//TODO: double in size
void circularbuffer::grow() {}
/*
   x / 2**n == x >> n
   x mod n == x & (n-1) when n is a power of 2

  11 % 7 == 4  15 clocks

   20 % 8

  000 = 0
  001 = 1
  010 = 2
  011 = 3
  100 = 4
  101 = 5
  110 = 6
  111 = 7
 1000

   x % 64     64 = 2**6
   
A  B    A AND B     A OR B     A XOR B
0  0      0           0          0
0  1      0           1          1
1  0      0           1          1
1  1      1           1          0


   int x = 12, y = 19;
     x=   01100
     y=   10011
   x&y    00000
   x|y    11111
   x^y    11111
  ~x      10011


 */


void circularbuffer::enqueue(uint32_t v) {
	p[tail] = v;
	tail = (tail + 1) & (capacity);
	//	if (tail >= capacity)  // this is same but slower
	//		tail = 0;
	if (tail == head) { // queue is full
		grow();
	}
}

uint32_t circularbuffer::dequeue() {
  uint32_t temp = p[head];
	head = (head + 1) & capacity;
	return temp;
}

bool circularbuffer::isEmpty() const {
  return head == tail;
}

#if 0
circularbuffer& circularbuffer::operator =(const circularbuffer& orig) {
	if (this != &orig ) {
    delete [] p;
		p = new uint32_t[orig.capacity];
		capacity = orig.capacity;
		head = orig.head;
		tail = orig.tail;
    for (int i = 0; i < capacity; i++)
			p[i] = orig.p[i];
		if (head < tail) {
			for (uint32_t i = head; i<tail; i++)
				p[i] = orig.p[i];
		} else if (head == tail){
			// copy nothing, the queue is empty
		} else {
			for (uint32_t i = head; i <= capacity; i++)
				p[i] = orig.p[i];
			for (uint32_t i = 0; i < tail; i++)
				p[i] = orig.p[i];
		}
	}
	return *this;
}
#endif

circularbuffer& circularbuffer::operator =(circularbuffer copy) {
  capacity = copy.capacity;
	head = copy.head;
	tail = copy.tail;
	swap(p, copy.p);
  return *this;
}


circularbuffer::circularbuffer(circularbuffer&& orig)
	: p(orig.p), capacity(orig.capacity), head(orig.head), tail(orig.tail) {
	orig.p = nullptr;
}



