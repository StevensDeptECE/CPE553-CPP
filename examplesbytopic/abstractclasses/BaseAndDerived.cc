class Base {

public:
  void f() { cout << "B"; }
};

class Derived : public Base {

public:
  void f() { cout << "D"; }
};

int main() {
  Base b;
  b.f(); // B

  Derived d;
  d.f(); // D

#if 0
// This will not work without virtual on base class void f()
  Base* bp = &b;
  bp->f(); // B

  bp = &d;
  bp->f(); // B
  #endif
}