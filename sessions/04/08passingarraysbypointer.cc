#include <iostream>
#include <cstdint>
using namespace std;

void setzero(uint64_t x[10][10]) {
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
        x[i][j] = 0;
}

void set(uint64_t* p, uint32_t size, uint32_t val) {
  for (int i = 0; i < size; i++)
    p[i] = val;
}

void print(const uint64_t* p, uint32_t size) {
  for (int i = 0; i < size; i++)
    cout << p[i] << ' ';
}

int main() {
  uint64_t a[10][10];
  uint64_t b[5][5];
  setzero(a);
  print(&a[0][0], 100);
  set(&b[0][0], 25, 3);
  print(&b[0][0], 25);

  const uint64_t c[2][3] = {7};
  print(&c[0][0], 6);
}