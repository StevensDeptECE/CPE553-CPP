#include <iostream>
using namespace std;

class A {
public:
  A() { cout << "born" << endl; }
  ~A() { cout << "died" << endl; }

};

void f() {
  A a2;
}
void g() {
  A a2;
}
static int x = f();
static int y = g();
A a1;
int main(){
  f();
  A a1;
  g();
}
