#include <iostream>
using namespace std;

int main() {
  uint64_t* a = new uint64_t[1000000];

  delete [] a;
  delete [] a;

}