#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream f("vec.txt");
  double x;
  while (!f.eof()) {
    f >> x;
    cout << x;
  }
}