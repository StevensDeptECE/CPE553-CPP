class A {
private:
  int size;
  int *p;

public:
  A(int size) : size(size), p(new int[size]) {
    for (int i = 0; i < size; i++)
      p[i] = i;
  }
  ~A() { delete[] p; }
  A(const A &orig) : size(orig.size), p(new int[orig.size]) {
    for (int i = 0; i < size; i++)
      p[i] = orig.p[i];
  }
  A &operator=(const A &orig) {
    if (this != &orig) {
      delete[] p;
      size = orig.size;
      p = new int[size];
      memcpy(p, orig.p, size * sizeof(int));
    }
    return *this;
  }
  // move constructor
  A(A &&orig) : size(orig.size), p(orig.p) { orig.p = nullptr; }
};

A f() {
  A temp(3);
  return temp;
}

int main() {
  A a1(5);
  A a2 = a1; // copy constructor
  A a3(a1);  // copy constructor
  a2 = a1;   // operator=
  a2 = f();
}
