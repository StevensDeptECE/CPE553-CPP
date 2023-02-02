#include <iostream>
using namespace std;

int main() {
    int a[10]; // 40 bytes
    double b[100]; // 800 bytes
    float c[4][10]; // 160 bytes

    int d = 3;

    int e[] = {4, 3, 2};
    double f[10] = {4, 3, 2}; // 4.0 3.0 2.0 0 0 0 0 0 0 0 
    double g[1000] = {0};
    //int x[1024*1024];
    int* x = new int[1024*1024];
    for (int i = 0; i < 10; i++)
      cout << a[i] << ' ';
    cout << '\n';

    for (int i = 0; i < 10; i++)
      a[i] = i;
    a[10] = 99;
    a[11] = 84;
    a[1000000] = 221;   
}