#include <iostream>
using namespace std;

int main() {
//    uint32_t age;
//    cin >> age;
//    cout << age << '\n';
    for (uint32_t age = 1; age <= 140; age++) {
      cout << age * 365 * 24 * 60 * 60  << '\n';
    }    
}