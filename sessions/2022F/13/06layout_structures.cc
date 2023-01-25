#include <iostream>

class A {
  char c; // 7 bytes padding
  double x;
  uint32_t d; // 4 bytes padding
  uint64_t e;
};

class Arearrange {
  double x;
  uint64_t e;
  uint32_t d;
  char c; // 3 bytes padding
};

class GravBody {
  bool isPlanet : 1;
  bool isMoon : 1;
  bool isGas : 1;
  bool isRocky : 1;
  int numOfMoons : 4;
};



int main() {
    std::cout << sizeof(A) << '\n'; //
    std::cout << sizeof(Arearrange) << '\n'; //
    std::cout << sizeof(GravBody);
}