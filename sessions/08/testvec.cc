#include <iostream>
#include <cstdint>
#include "vec3d.hh"

void testvec1(uint32_t n) {
  for (int i = 0; i < n; i++) {
    vec3d_inline v(1,2,3);
  }
}

double testvec2(uint32_t n) {
    double sum = 0;
  for (int i = 0; i < n; i++) {
    vec3d_inline v(1,2,3);
    sum += v.abs();
  }
  return sum;
}

double testvec3(uint32_t n) {
    double sum = 0;
  for (int i = 0; i < n; i++) {
    vec3d_inline v(i,2,3);
    sum += v.abs();
  }
  return sum;
}

uint64_t testintegers(uint32_t n) {
    uint64_t prod = 1;
    for (uint32_t i = 0; i < n; i++)
      prod *= i;
    return prod;
}

int main() {
    constexpr uint32_t n = 2000000000;
 //   testvec1(n);
 //testvec2(n);
 //std::cout << testintegers(n);
}