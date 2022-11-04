#include <iostream>
using namespace std;

int main() {
  uint64_t* a = new uint64_t[1000000];
  uint64_t* p = a;
  a++; // a points to a[1]
 
  //delete [] a; // this will crash
  delete [] p;

}