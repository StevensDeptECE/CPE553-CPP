#include <time.h>
#include <iostream>
using namespace std;
int main() {
    clock_t t0 = clock();

        const int n = 1000'000'000;
   double sum = 0;
    for (int i = 0; i < n; i++)
    sum += i / 5.0;
    clock_t t1 = clock();
    cout << (t1-t0)*1e-3 << '\n';
}