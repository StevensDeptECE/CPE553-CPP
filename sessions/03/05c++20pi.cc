#include <iostream>
#include <iomanip>
#include <numbers>
using namespace std;
//using std::numbers;
int main() {
    double x=    std::numbers::pi;
    cout << setprecision(16);
    cout << x << '\n';

    cout << 1.251611111111123 << '\n';
}