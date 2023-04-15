#include <iostream>

template<typename T>
class DynArray {
private:
  T* p;
  uint32_t capacity;
  uint32_t size;
  void grow() {

  }
public:
  DynArray(uint32_t capacity) : capacity(capacity), size(0), p(new T[capacity]) {}
  ~DynArray() {
    delete [] p;
  }
  DynArray(const DynArray& orig) = delete;
  DynArray operator=(const DynArray& orig) = delete;
  void add(const T& v) {
    if (size >= capacity)
      grow();
    p[size] = v;
    size++;
  }
};

int main() {
    DynArray<int> a(50);
    for (int i = 0; i < 50; i++)
      a.add(i);
// next time   DynArray b = a;
// b = a;
}