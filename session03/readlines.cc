#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream f("var.csv");
    char buffer[4096]; // make a buffer definitely big enough to hold a line
    char a[4096]; // only way to be sure each variable cannot overflow
    char b[4096]; // is to make each one as big as the entire buffer? seem ridiculous
    char c[4096];
    while (f.getline(buffer, sizeof(buffer))) { // if there is a line
      isstream line(buffer); // read each line from a string stream attached to the buffer
      line >> a >> b >> c;
      // strlen(a)  strlen(b)    strlen(c) "12.345"
      char name[4];
      int year = atoi(b);
      float val = atof(c);
      line >> name >> year >> val;
      // do something with the three columns...
    }
}
