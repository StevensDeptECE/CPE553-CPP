#include <fstream>
using namespace std;

int main() {
    int x[2048] = { 1, 257};
    ofstream f("test.dat");
    const int n = 20'000;
    for (int i = 0; i < n; i++)
        f.write((char*)x, 2048 * sizeof(int));
}