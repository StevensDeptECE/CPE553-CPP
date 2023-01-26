#include <iostream>

using namespace std;

int main() {
  uint8_t a = 0; // 255
  uint16_t b = 0; // 65535
  uint32_t c = 0; // 4'200'000'000;
  uint64_t d = 0; // 123456789012345678ULL;


  uint32_t e = 5 + 6;
  uint8_t f = 128 * 4;  //f=0    00000000 = 0     11111111=255   100000000
  uint16_t g = 65534 + 4; //g =2

  uint32_t h = 17 / 3;
  uint32_t i = 17 % 3; 
}