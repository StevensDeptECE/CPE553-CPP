#include <iostream>
#include <fstream>
#include <vector>
using  namespace std;

int main() {
    ifstream f("a.txt");
    vector<int> a;
    int n;
    while (f >> n) {
      a.push_back(n);
    }
}