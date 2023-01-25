#include <iostream>

using namespace std;

void f();

int main() {
  for (int i = 0; i < 1000000000; i++)
    f();
}