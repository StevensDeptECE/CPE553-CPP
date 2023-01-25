#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i <= 10; i++)
      sum = sum + i;
    cout << "sum=" << sum << '\n';
    int prod = 1;
    for (int i = 1; i <= 10; i++)
      prod = prod * i;

    cout << "prod=" << prod << '\n';

}