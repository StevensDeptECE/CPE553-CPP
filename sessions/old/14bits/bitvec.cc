#include <iostream>
#include <memory.h>
using namespace std;

class Bitvec {
private:
	uint64_t size; // the number of bits in the bitvec
	uint64_t WORDS;
	uint64_t* p;
public:
	Bitvec(uint64_t size) : size(size), WORDS((size+63)/64),
													p(new uint64_t[(size+63)/64] ) {
		for  (uint64_t i = 0; i < WORDS; i++)
			p[i] = 0;
	}
	~Bitvec() {
    delete [] p;
	}
	Bitvec(const Bitvec& orig) : size(orig.size), WORDS(orig.WORDS),
															 p(new uint64_t[orig.WORDS]) {
		memcpy(p, orig.p, WORDS * sizeof(uint64_t));
	}

  Bitvec& operator =(Bitvec copy) {
    size = copy.size;
		WORDS = copy.WORDS;
		swap(p, copy.p);
		return *this;
	}
	
	Bitvec(Bitvec&& orig) : size(orig.size), WORDS(orig.WORDS), p(orig.p) {
		orig.p = nullptr;
	}
	void set(bool b) {
		uint64_t val = b ? 0xFFFFFFFFFFFFFFFFULL : 0;
		for (uint64_t i = 0; i < WORDS; i++)
			p[i] = val;
	}


	//  0000 0000 0000 0000 0x00 0000 0000 0000
	//  0000 0000 0000 0000 0000 0000 0000 0001 = mask
	// shift left to correct position and use 
	//  0000 0000 0000 0000 0100 0000 0000 0000 = mask
	void set(uint64_t pos) {
    // first compute the word (array element)
		// then compute the bit within the word

		//		p[pos / 64]      1 << (pos % 64)
		//      pos >> 6             pos & 63
		p[pos / 64] |= 1 << (pos % 64);
	}

	void clear(uint64_t pos) {
		p[pos / 64] &= ~(1 << (pos % 64)); // XOR with 1 inverts the bit		
	}
	void toggle(uint64_t pos) {
		p[pos / 64] ^= 1 << (pos % 64); // XOR with 1 inverts the bit
	}
	bool test(uint64_t pos) {
		return (p[pos / 64] & (1 << (pos % 64))) != 0;
	}
};

int main() {
	Bitvec b(70); // allocate 70 bits, assign 0 to all
	b.set(true); // set them all to true

	b.clear(4); // make bit 4 = 0
	b.toggle(5); // if true --> false, if false --> true
	b.set(5); // make bit 5 = 1
	cout << b.test(5);
	cout << b;
}
	
