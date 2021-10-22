#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("test.dat");
    int x,y,z;
    while (f >> x >> y >> z) {
        cout << (x+y+z) << '\n';
    }

}