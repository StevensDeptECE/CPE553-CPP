#include <iostream>
#include "memory.h"
using namespace std;

class BitVec {
private:
	uint64_t size;
	uint64_t* bits;
	BitVec(uint64_t size, const char* priv) : size(size), bits(new uint64_t[(size+63)/64]) {
	}
public:
  BitVec(uint64_t size) : size(size), bits(new uint64_t[(size+63)/64]) {
		memset(bits, 0, (size+63)/64 * sizeof(uint64_t));
	}
	~BitVec() {
		delete [] bits;
	}

  BitVec(const BitVec& orig) = delete;
		//TODO:
		//	}

	// copy and swap
		BitVec& operator =(BitVec orig) = delete;
		//TODO:
	//		return *this;
	//	}

	// move constructor
	BitVec(BitVec&& orig) : size(orig.size), bits(orig.bits) {
		orig.bits = nullptr;
	}

#if 0
	bool test(uint64_t pos) const { // return true or false: bit at position pos
		//TODO: AND
	}
#endif
	
	void set(uint64_t pos) { // set bit at position pos to 1
		bits[pos / 64] |= (1ULL << (pos % 64));
		// bits[pos >> 6  ] |= (1ULL << (pos & 63));
	}
	
	void clear(uint64_t pos) { // set bit at position pos to 0
		// TODO: AND WITH NOT
	}
	void toggle(uint64_t pos) { // invert bit at position pos
		//TODO: XOR
	}
	friend BitVec operator |(const BitVec& a, const BitVec& b) //throw (const char*){
	{
		//		if (a.size != b.size)
		//			throw "badsize";
		BitVec ans(a.size, "uninitialized");
		const uint64_t size = (a.size+63)/64;
		for (uint64_t i = 0; i < size; i++)
			ans.bits[i] = a.bits[i] | b.bits[i];
		return ans;
	}
#if 0
	friend BitVec operator &(const BitVec& a, const BitVec& b) {

	}
	friend BitVec operator ^(const BitVec& a, const BitVec& b) {

	}
	friend BitVec operator |=(const BitVec& a, const BitVec& b) {

	}
	friend BitVec operator &=(const BitVec& a, const BitVec& b) {

	}
	friend BitVec operator ^=(const BitVec& a, const BitVec& b) {

	}
#endif
	friend ostream& operator <<(ostream& s, const BitVec& b) {
		
		const uint64_t size = (b.size+63)/64;
		for (uint64_t i = 0; i < size; i++) {
			uint64_t v = b.bits[i];
			for (uint64_t mask = 1ULL << 63; mask > 0; mask >>= 1)
  			s << (v & mask ? '1' : '0');
		}
		return s;
	}
};

int main() {
	BitVec a(64);
	a.set(5);
	BitVec b(64);
	b.toggle(6);
	BitVec c = a | b;
	cout << c << '\n';
}
