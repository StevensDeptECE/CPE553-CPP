#include <iostream>
#include <utility>
class DynArray {
private:
  int* data;
  int len;
public:
  DynArray() : data(nullptr), len(0) {}
  ~DynArray() {
    delete [] data;
  }
  DynArray(const DynArray& orig) : data(new int[orig.len]), len(orig.len) {
    for (int i = 0; i < len; i++)
      data[i] = orig.data[i];
//FASTER:      memcpy(data, orig.data, len * sizeof(int));
  }

#if 0
  // old operator = (pre 2011)
  void operator =(const DynArray& orig) {
    if (this == &orig)
      return;
    delete [] data; // first delete what we had
    data = new int[orig.len]; // allocate enough to hold copy
    len = orig.len; // copy the len
    for (int i = 0; i < len; i++) // copy from orig to this
      data[i] = orig.data[i];
  }
#endif
// copy and swap paradigm
  DynArray& operator =(DynArray copy) {
    len = copy.len;
    std::swap(data, copy.data);
    return *this; // return ME, the object
  }
  DynArray(DynArray&& orig) : data(orig.data), len(orig.len) {
    orig.data = nullptr;
  }

  void add(int v) {
    const int* old = data;
    data = new int[len+1];
    for (int i = 0; i < len; i++) // copy from orig to this
      data[i] = old[i];
    delete [] old;
    len++;
  }

};

void f(DynArray x) {

}

DynArray g() {
  DynArray temp;
  temp.add(5);

  return temp;
}

int main() {
  DynArray a;
  a.add(3);
  for (int i = 0; i < 10; i++)
    a.add(i);
  DynArray b = a; // calls copy constructor
  DynArray c(a); // calls copy constructor
  b.add(1);
  a = c = b;
  //c = c;
  f(b);
}