#include <iostream>
#include "benchmark.hh"
using namespace std;

void bench1() {
    const int n = 100'000'000;
   double sum = 0;
    for (int i = 0; i < n; i++)
    sum += i / 5.0;
}
int main() {
    benchmark::benchOnce("add and divide", 10, bench1);
}