#include <iostream>
using namespace std;

int main() {
    for (int a = 3; a < 19; a = a + 2) { // 3 5 7 9 11 13 15 17  
      cout << a << ' ';
    }

    // 10 9 8 7 6 5 4 3 2 1 0

    for (int i = 10; i >= 0; i--)
      cout << i << '\n';


    // 1 2 4 8 16 32 64 128
    for (int x = 1; x <= 128; x = x * 2) // x*= 2
      cout << x << ' ';
}