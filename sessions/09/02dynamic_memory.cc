#include <iostream>
using namespace std;
int main() {
  // old C way
  int* a = (int*)malloc(1000 * sizeof(int)); // in bytes
  free(a);
// both can be used in a program, but must match

// new C++ way
  int* p = new int[100000000];  //allocated on heap 400Mb
//  delete [] p; // memory leak

  int* q = new int[1000000000];  //4Gb
  delete [] q;

  int* r = new int[10000000000];  //40Gb we have not only 4GB
  delete [] r;

  // uint8_t* p;
  // Note: WebPEncodeLosslessRGBA(....., &p)

  // WebPFree(p);
}