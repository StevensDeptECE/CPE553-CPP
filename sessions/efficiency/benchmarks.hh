#include <cstdint>
uint64_t callfunc(uint32_t n);
uint64_t sum1Ton(uint32_t n);
uint64_t sumDiv(uint32_t n);
uint64_t sumDiv2(uint32_t n);
float sum_float(uint32_t n);
float prod_float(uint32_t n);
double sum_double(uint32_t n);
double prod_double(uint32_t n);
double sum(const double a[], uint32_t n);
double prod(const double a[], uint32_t n);

void empty2(uint64_t* p, uint32_t n);
uint64_t readMem8(uint8_t* p, uint32_t n);
uint64_t readMem16(uint16_t* p, uint32_t n);
uint64_t readMem32(uint32_t* p, uint32_t n);
uint64_t readMem64(uint64_t* p, uint32_t n);
void writeMem8(uint8_t* p, uint32_t n);
void writeMem16(uint16_t* p, uint32_t n);
void writeMem32(uint32_t* p, uint32_t n);
void writeMem64(uint64_t* p, uint32_t n);
void readWriteMem(uint64_t* p, uint32_t n);
void writeReadMem(uint64_t* p, uint32_t n);
void copyMem(uint64_t* dest, uint64_t* src, uint32_t n);

