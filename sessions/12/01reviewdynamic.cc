#include <cstring>

class dynamicarray {
private:
  int* p;
  uint32_t size;
public:
  dynamicarray() : p(nullptr), size(0) {}
  ~dynamicarray() {
    delete [] p;
  }
  dynamicarray(const dynamicarray& orig) :
   p(new int[orig.size]), size(orig.size) {
    memcpy(p, orig.p, size*sizeof(int));
   }
  dynamicarray& operator =(dynamicarray copy) {
    size = copy.size;
    swap(p, copy.p);
    return *this;
  }

  dynamicarray(dynamicarray&& orig) : p(orig.p), size(orig.size) {
    orig.p = nullptr;
  }
  void add(int v) {
    const int* old = p;
    p = new int[size+1];
    for (int i = 0; i < size; i++)
      p[i] = old[i];
    delete [] old;
    p[size] = v;
    size++;
  }
};

void f(dynamicarray x) {}
dynamicarray g() {
    dynamicarray x;
    x.add(9);
    return x;
}

int main() {
    dynamicarray a;
    dynamicarray b = a;
    dynamicarray c(a);
    dynamicarray d;
    d.add(1);

    d = c = b = a;
}