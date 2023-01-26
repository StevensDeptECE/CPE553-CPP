#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    const int n = 4;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << setw(4) << (i*j);  // printf("%4d", 124)
      }
      cout << endl;
    }
}