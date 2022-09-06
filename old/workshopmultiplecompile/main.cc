#include "Circle.hh"
#include "Rect.hh"
#include <vector>
#include <iostream>
using namespace std;

int main() {
  Circle c(10, 20, 5);
  Rect r(100,200, 50,50);
  vector<Shape*> shapes;
  shapes.push_back(&c);
  shapes.push_back(&r);
  for (auto s : shapes) {
    cout << s->area() << '\n';
  }
}