#include <iostream>
#include <cstdint>

int main() {
	char e = 'a'; // 1 byte (usually)    sizeof(char) == 1
	short d = 1; // >= 2 bytes (16 bits) <= int
	int a = 1; //  4 bytes  signed or unsigned???
	signed int sa;
	unsigned int ua;
	long b = 1234567890; // short <= int <= long <= long long 
  long long c = 12412151241241LL; //
	uint32_t x;
	uint64_t y;
	//	uint8_t uint16_t uint32_t uint64_t
	// int8_t  int16_t  int32_t int64_t
	// _int128
}
