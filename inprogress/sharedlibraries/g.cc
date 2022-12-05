#include <cstdint>
// using the C calling convention
extern "C" {
	uint64_t g(uint64_t a, uint64_t b) {
		return a + b;
	}
}

// using the C++ calling convention
uint64_t h(uint64_t a, uint64_t b) {
	return a + b;
}
