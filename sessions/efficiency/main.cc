/*
	author: Dov Kruger

	Grand unified benchmarking for all kinds of system activity including:

	1. Elementary arithmetic operations (add,sub,mult, div)
	2. Reading and writing sequentially in memory
	3. Reading while computing (measuring pipelining ability)
	4. Computation with branch prediction (an if statement in a loop)
	5. Calling functions
	6. Passing parameters to functions
	7. calling functions in a shared library
  8. I/O on a block-oriented device (both small numbers of bytes and a block at a time)
 */
#include <iostream>

#include "benchmark.hh"
#include "benchmarks.hh"
#include <cstring>
using namespace std;

uint64_t* p;
uint64_t* p2;

void operation_benchmarks() {
	constexpr uint32_t n = 100000000; // 100 million for common integer ops
	constexpr uint32_t trials = 10;
	
	benchmark<>::bench("empty function call", trials, []() { callfunc(n); } );
	benchmark<>::bench("sum 1 to n", trials, []() { sum1Ton(n); } );
	benchmark<>::bench("sum and divide", trials, []() { sumDiv(n); } );
	benchmark<>::bench("sum with 2 divisions", trials, []() { sumDiv(n); } );
#if 0
	float sum(uint32_t n);
	float prod(uint32_t n);
	double sum(uint32_t n);
	double prod(uint32_t n);
double sum(const double a[], uint32_t n);
double prod(const double a[], uint32_t n);
void empty2(uint64_t* p, uint32_t n);
	#endif

 constexpr uint32_t n2 = 10000000; // 10 million for memory operations

 // create 64-bit block for all memory tests
 p = new uint64_t[n2];
 memset(p, 0, n2 * sizeof(uint64_t)); // zero out block to warm up cache

 
 benchmark<>::bench("readMem8", trials, []() { readMem8((uint8_t*)p, n2*8); } );
 benchmark<>::bench("readMem16", trials, []() { readMem16((uint16_t*)p, n2*4); } );
 benchmark<>::bench("readMem32", trials, []() { readMem32((uint32_t*)p, n2*2); } );
 benchmark<>::bench("readMem64", trials, []() { readMem64(p, n2); } );
 benchmark<>::bench("writeMem8", trials, []() { writeMem8((uint8_t*)p, n2*8); } );
 benchmark<>::bench("writeMem16", trials, []() { writeMem16((uint16_t*)p, n2*4); } );
 benchmark<>::bench("writeMem32", trials, []() { writeMem32((uint32_t*)p, n2*2); } );
 benchmark<>::bench("writeMem64", trials, []() { writeMem64(p, n2); } );

 benchmark<>::bench("readWriteMem", trials, []() { readWriteMem(p, n2); } );

 p2 = new uint64_t[n2]; // create 2nd 64-bit block to copy to
 benchmark<>::bench("copyMem", trials, []() { copyMem(p, p2, n2); } );
 delete [] p;
 delete [] p2;
}

int main() {
	operation_benchmarks();
	
}
