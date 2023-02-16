#include <iostream>
using namespace std;

class DynamicMem {
private:
    int* p;
    uint32_t size;
public:
    DynamicMem(uint32_t size) : p(new int[size]), size(size) {    }
    void set(int i, int val) { p[i] = val; }
    ~DynamicMem() {
        delete [] p;
    }
    // copy constructor
    DynamicMem(const DynamicMem& orig) : p(new int[orig.size]), size(orig.size) {
        for (int i = 0; i < size; i++)
          p[i] = orig.p[i];
    }
};

int main() {
  DynamicMem x(32);
  x.set(3, 92);
  x.set(5, 11);
  int a = 3;
  int b = a;
  DynamicMem y = x; // y contains p pointing to same memory as x
}