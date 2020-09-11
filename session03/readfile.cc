#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream f("grades.txt");
    double v;
    while (!f.eof()) {
        f >> v;
        cout << v << ' ';
    }
}