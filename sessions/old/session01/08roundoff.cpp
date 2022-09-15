#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << setprecision(8);
    for (float x = 0; x < 10; x += 0.1) {
        cout << x << ' ';
    }

    float sum = 0;
    for (float i = 1; i <= 5; i++) {
      sum = sum + 1.0/i;
    }
    cout << "sum=" << sum << '\n';
}