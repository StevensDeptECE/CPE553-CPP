#include "lib1.hh"

extern "C" {
uint64_t f(uint64_t a, uint64_t b) {
	return a + b;
}
};
