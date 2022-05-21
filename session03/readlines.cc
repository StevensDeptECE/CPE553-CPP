#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  ifstream f("test.txt");
  char buffer[4096];  // make a buffer definitely big enough to hold a line
  char name[20];
  double mass;
  double radius;

  while (f.getline(buffer, sizeof(buffer))) {  // if there is a line
    istringstream line(buffer);
    if (line >> name >> mass >> radius) { // Check that reads succeeded
      cout << "name=" << name << " mass=" << mass << " radius=" << radius
           << '\n';
    }
  }
}
