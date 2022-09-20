#include <cstdint>
#include "lib1.hh"
#include "lib2.hh"
#include <unistd.h>
#include <fcntl.h>

void empty();
void empty(uint32_t, uint32_t);
void empty(uint32_t, uint32_t, uint32_t);
void empty(double x);
void empty(double x, double y);
void empty(double x, double y, double z);


uint64_t callfunc(uint32_t n) {
	for (uint32_t i = 0; i < n; i++)
		empty();
	return 0;
}

uint64_t callfunc2params(uint32_t n) {
	for (uint32_t i = 0; i < n; i++)
		empty(i,i);
	return 0;
}

uint64_t callfunc3params(uint32_t n) {
	for (uint32_t i = 0; i < n; i++)
		empty(i,i,i);
	return 0;
}

uint64_t sum1Ton(uint32_t n) {
	uint64_t s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;
}

uint64_t sumDiv(uint32_t n) {
	uint64_t s = 0;
	for (int i = 1; i <= n; i++)
		s += 1/i;
	return s;
}

uint64_t sumDiv2(uint32_t n) {
	uint64_t s = 0;
	for (int i = 1; i <= n; i++)
		s += 1/i + 2/i;
	return s;
}


void empty2(uint64_t* p, uint32_t n) {
}

uint64_t readMem8(const uint8_t p[], uint32_t n) {
	uint64_t sum = 0;
	for (int i = 0; i < n; ++i)
		sum += p[i];
	return sum;
}

uint64_t readMem16(const uint16_t p[], uint32_t n) {
	uint64_t sum = 0;
	for (int i = 0; i < n; ++i)
		sum += p[i];
	return sum;
}

uint64_t readMem32(const uint32_t p[], uint32_t n) {
	uint64_t sum = 0;
	for (int i = 0; i < n; ++i)
		sum += p[i];
	return sum;
}

uint64_t readMem64(const uint64_t p[], uint32_t n) {
	uint64_t sum = 0;
	for (int i = 0; i < n; ++i)
		sum += p[i];
	return sum;
}

// write zeros into a block of memory n elements long, 8 bits at a time
void writeMem8(uint8_t* p, uint32_t n) {
	for (int i = 0; i < n; ++i)
		p[i] = 0;
}

// write zeros into a block of memory n elements long, 16 bits at a time
void writeMem16(uint16_t* p, uint32_t n) {
	for (int i = 0; i < n; ++i)
		p[i] = 0;
}

// write zeros into a block of memory n elements long, 32 bits at a time
void writeMem32(uint32_t* p, uint32_t n) {
	for (int i = 0; i < n; ++i)
		p[i] = 0;
}

// write zeros into a block of memory n elements long, 64 bits at a time
void writeMem64(uint64_t* p, uint32_t n) {
	for (int i = 0; i < n; ++i)
		p[i] = 0;
}


/**
	 Read and write memory.  Repeating access of memory
	 should be affected by cache, but in this case reading first
	 won't help writing because that writing should have to write 
	 through to main memory.  So we will benchmark writeRead also.
*/
void readWriteMem(uint64_t* p, uint32_t n) {
  readMem64(p, n);
	writeMem64(p, n);
}

/**
	 Write then read memory.
	 Cache should help this but if n is big enough we will miss cache and slow down.

*/
void writeReadMem(uint64_t* p, uint32_t n) {
	writeMem64(p, n);
  readMem64(p, n);
}

void copyMem(uint64_t* dest, uint64_t* src, uint32_t n) {
	while (n-- > 0) {
		*dest++ = *src++;
	}
}

uint32_t calllib1(uint32_t n) {
	uint32_t sum = 0;
	for (uint32_t i = 0; i < n; i++) {
		sum += libraryFunc1(i, i);
	}
	return sum;
}

uint32_t calllib2(uint32_t n) {
	uint32_t sum = 0;
	for (uint32_t i = 0; i < n; i++) {
		sum += libraryFunc2(i, i);
	}
	return sum;
}

float sum_float(uint32_t n) {
	float sum = 0;
	float x = 0;
	for (uint32_t i = 0; i < n; i++)
		sum += x++;
	return sum;
}

float prod_float(uint32_t n) {
	float prod = 1;
	float x = 1;
	for (uint32_t i = 0; i < n; i++, x += 0.001)
		prod *= x;
	return prod;
}

double sum_double(uint32_t n) {
	double sum = 0;
	double x = 0;
	for (uint32_t i = 0; i < n; i++)
		sum += x++;
	return sum;
}

double prod_double(uint32_t n) {
	float prod = 1;
	float x = 1;
	for (uint32_t i = 0; i < n; i++, x += 0.001)
		prod *= x;
	return prod;
}

void writeBytesToDiskSize(const char filename[], uint32_t n, uint32_t blockSize) {
	char buf[blockSize] = {0};
	int fh = open(filename, O_WRONLY);
	for (uint32_t i = n / blockSize; i > 0; i--)
		write(fh, buf, sizeof(blockSize));
	if (n % blockSize != 0) { // extra last write if not evenly aligned
		write(fh, buf, n  % blockSize);
	}
	close(fh);
}

void empty() {}
void empty(uint32_t, uint32_t) {}
void empty(uint32_t, uint32_t, uint32_t) {}
void empty(double x) {}
void empty(double x, double y) {}
void empty(double x, double y, double z) {}

