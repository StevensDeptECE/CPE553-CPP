#include <iostream>
using namespace std;

/*
  pointers in objects. Spot the errors
*/

class Car {
private:
  int count;
  int* components;
  public:
  Car() : count(0) {
    components = new int[10];
  }
  void add(int v) {
    if (count < 10)
      components[count++] = v;
    else {
      components = new int[20]; // memory leak
      components[count] = v;
    }
  }
  ~Car() {
    free(components);
  }
};

int main() {
  Car c1;
  c1.add(5);
  for (int i = 0; i < 10; i++)
    c1.add(i); // 5 0 1 2 3 4 5 6 7 8 9
}
