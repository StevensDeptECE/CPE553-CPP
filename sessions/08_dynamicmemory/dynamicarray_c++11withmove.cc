#include <iostream>
using namespace std;

class dynamicarray {
private:
  int* p;
  uint32_t size;
public:
  dynamicarray() : p(nullptr), size(0) {}
  ~dynamicarray() {
    delete [] p;
  }
  dynamicarray(const dynamicarray& orig) : size(orig.size), p(new int[orig.size]) { 
    for (int i = 0; i < size; i++)
      p[i] = orig.p[i];
  }

  dynamicarray& operator =(dynamicarray copy) {
    this->size = copy.size;
    swap(this->p, copy.p);
    return *this;
  }

  //move constructor: when copying a temp (which is going away anyway)
  dynamicarray(dynamicarray&& orig) : p(orig.p), size(orig.size) {
    orig.p = nullptr;
  }

  void add(int v) {
    const int* old = p; // remember the old memory
    p = new int[size+1];
    for (int i = 0; i < size; i++) // copy the old list into the new memory
      p[i] = old[i];
    p[size] = v; // add the new element to the end of the list
    size++; // grow the list by 1
    delete [] old;
  }
};

void f(dynamicarray x) {
  // any change to x does not change the original
  cout << "this makes a copy of the parameter x. Will crash if you don't write copy constructor\n";
}

dynamicarray g(int size) {
  dynamicarray temp;
  for (int i = 0; i < size; i++)
    temp.add(i*2);  // 0 2 4 6 8 10...
  return temp; // returns a copy of temp, will crash if you don't write copy constructor
}

int main() {
  dynamicarray a;
  for (int i = 0; i < 10; i++)
    a.add(i); // add the number i to the end of the list    0 1 2 3
  dynamicarray b = a; // b is a copy of a (calls copy constructor)
  dynamicarray c(a); // b is a copy of a (calls copy constructor)
  dynamicarray e;
  e.add(7); // create an array with just 1 element
  c = e; // this should give back the 10 elements, then copy e
  e = e;
  a = b = c = e;
  f(c);
  dynamicarray d = g(5); // 0 2 4 6 8
}