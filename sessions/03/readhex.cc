#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream f("hex.txt");
    int color;
    f >> hex >> color;
    cout << color << '\n';
}