#include <iostream>
using namespace std;

uint32_t sum(uint32_t a, uint32_t b) {
    uint32_t s = 0;
    for (uint32_t i = a; i <= b; i++)
      s += i;
    return s;
}


uint32_t prod(uint32_t n) {
    uint32_t p = 1;
    for (uint32_t i = 1; i <= n; i++)
      p *= i;
    return p;
}

int main() {
    cout << sum(5, 7) << '\n';
    cout << prod(5) << '\n';
}