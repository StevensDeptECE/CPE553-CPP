#include <iostream>
using namespace std;
void f(double& a) {
  cout << a;
}

void g(double b) {
  cout << b;
}

int main() {
  int x = 10;
  f(x); // why is this call illegal
  g(x); // when this one is fine?
}
