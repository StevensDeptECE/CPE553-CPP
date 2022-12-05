#include <iostream>
using namespace std;

extern "C" {
uint64_t f(uint64_t a, uint64_t b);
};

extern "C" {
uint64_t g(uint64_t a, uint64_t b);
}
uint64_t h(uint64_t a, uint64_t b);

int main() {
  uint64_t c = f(2, 3); // call function f in shared library, add 2+3
  cout << c << '\n';
	c = g(2,3);
  cout << c << '\n';
	c = h(2,3);
  cout << c << '\n';
}
