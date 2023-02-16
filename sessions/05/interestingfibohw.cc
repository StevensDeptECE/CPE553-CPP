#include <iostream>
using namespace std;

int fibo(int n) {
    // a = 2 b = 3  c = 5
    int f[n]; // int*f = new int[n];
    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i < n; i++)
        f[i] = f[i-1] + f[i-2];
    return f[n-1];
}

int main() {
    cout << fibo(10) << '\n';
}