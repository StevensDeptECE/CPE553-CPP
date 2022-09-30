#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  vector<Shape*> shapes;
                                              //r,g,b
  shapes.push_back(new Circle(100, 200, 50,    1.0,0,0)); // bright red circle
  shapes.push_back(new Rect(200, 300, 50, 40,  0,1,0)); // bright green rect
  shapes.push_back(new Triangle(100, 500, 300,600, 400,500, 0,0,1)); //bright blue triangle
  

  //circle has to print r g b setrgbcolor x y r 0 360 arc fill
  //   1 0 0 setrgbcolor 100 200 50 0 360 arc fill

  // rect
  // r g b setrgbcolor x y moveto x+w y lineto x+w y+h lineto x y+h lineto closepath fill

  // triangle
  // r g b setrgbcolor x y moveto x2 y2 lineto x3 y3 lineto closepath fill

  ofstream f("out.ps")
  for (auto s : shapes) {
    s->print(f);
  }
  for (auto s : shapes) {
    delete s; // free the memory used by each shape after we are done
  }
}