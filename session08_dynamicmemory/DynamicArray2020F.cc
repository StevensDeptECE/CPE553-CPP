#include <iostream>
#include <memory.h>

class DynamicArray {
private:
  uint32_t capacity;
  uint32_t size;
  int* arr;  
  /*
    remember the old memory
    allocate new memory 2x
    copy the old to the new
    delete the old memory
  */
  void grow() {
    int* old = arr;
    arr = new int[capacity*=2];
    for (int i = 0; i < size; i++)
      arr[i] = *(old+i);
    delete [] old;
      //memcpy(arr, old, capacity*sizeof(int))

    // memcpy checks whether regions overlap, this takes startup time
    //  memcpy(a+6, a, 10);
  }
public:
  DynamicArray(uint32_t initial_capacity = 1) : capacity(initial_capacity), size(0), arr(new int[initial_capacity]) {
  }
  ~DynamicArray() {
     delete [] arr;
  }
   // DynamicArray(const DynamicArray& orig) = delete; //C++11 no copying allowed

  DynamicArray(const DynamicArray& orig) : capacity(orig.capacity), size(orig.size), arr(new int[orig.capacity]) {
    memcpy(arr, orig.arr, orig.size * sizeof(int));
  }
  DynamicArray& operator =(const DynamicArray& orig) {
      if (this != &orig) {
        delete [] arr;
        capacity = orig.capacity;
        size = orig.size;
        arr = new int[orig.capacity];
        memcpy(arr, orig.arr, orig.size * sizeof(int));
      }
      return *this;
  }

  void addEnd(int v) {
      if (size >= capacity) {
          grow();
      }
      arr[size++] = v;
  }
  friend std::ostream& operator <<(std::ostream& s, const DynamicArray& a) {
      for (int i = 0; i < a.size; i++)
        s << a.arr[i] << ',';
      return s;
  }
  int& operator [](int i) {
    return arr[i];
  }
  int operator [](int i) const {
      return arr[i];
  }
};

using namespace std;
void f(DynamicArray d) {

}

int main() {
    DynamicArray a(5);
    for (int i = 0; i < 10; i++)
      a.addEnd(i);
    a.addEnd(-2);
    //a.removeEnd();
    cout << a << '\n';
    cout << a[3] << '\n';
    a[3] = 11;
    DynamicArray b = a; // calls COPY CONSTRUCTOR
    DynamicArray c(a); // calls COPY CONSTRUCTOR
    DynamicArray d(3);
    d[2] = 99;
    a = d;
    a = a;
    f(a);
}