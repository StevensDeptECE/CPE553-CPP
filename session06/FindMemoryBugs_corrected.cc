#include <iostream>
using namespace std;

/*
  pointers in objects. Spot the errors
*/

class Car {
private:
  int count;
  int capacity;
  int* components;
  public:
  Car() : count(0), capacity(10) {
    components = new int[capacity];
  }
  void add(int v) {
    if (count < capacity)
      components[count++] = v;
    else {
      const int* old = components;
      capacity *= 2;
      components = new int[capacity]; // memory leak
      for(int i = 0; i < count; i++) {
        components[i] = old[i];
      }
      delete [] old;
      components[count] = v;
    }
  }
  ~Car() {
    delete [] components;
  }
};

int main() {
  Car c1;
  c1.add(5);
  for (int i = 0; i < 10000; i++)            // if we grow to 1000, this will crash! (not anymore!)
    c1.add(i); // 5 0 1 2 3 4 5 6 7 8 9
}
