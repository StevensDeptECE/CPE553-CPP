#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main() {
    ifstream f("test.dat");
    char buffer[256];
    double x,y;

#if 0
// this loop cannot handle any bad characters in the input
    while (f >> x >> y) {
        cout << x << " " << y;
    }
#endif

// this at least reads one line each time, and if y is bad, oh well
    while (f.getline(buffer, sizeof(buffer))) {
      istringstream line(buffer);
      line >> x >> y;
      cout << x << "," << y;
    }
}