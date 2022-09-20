#include <cstdint>
uint64_t callfunc(uint32_t n);
uint64_t callfunc2params(uint32_t n);
uint64_t callfunc3params(uint32_t n);
uint32_t calllib1(uint32_t n);
uint32_t calllib2(uint32_t n);

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
uint64_t readMem8(const uint8_t p[], uint32_t n);
uint64_t readMem16(const uint16_t p[], uint32_t n);
uint64_t readMem32(const uint32_t p[], uint32_t n);
uint64_t readMem64(const uint64_t p[], uint32_t n);
void writeMem8(uint8_t* p, uint32_t n);
void writeMem16(uint16_t* p, uint32_t n);
void writeMem32(uint32_t* p, uint32_t n);
void writeMem64(uint64_t* p, uint32_t n);
void readWriteMem(uint64_t* p, uint32_t n);
void writeReadMem(uint64_t* p, uint32_t n);
void copyMem(uint64_t* dest, uint64_t* src, uint32_t n);

void writeBytesToDiskSize(const char filename[], uint32_t n, uint32_t blockSize);
