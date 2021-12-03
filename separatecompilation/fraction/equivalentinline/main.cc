#include "fraction.hh"

using namespace std;
int main() {
    const fraction f1(1,2); //  1/2
    fraction f2(1,3); // 1/3
    fraction f3 = f1 + f2; // implement as a member function

    cout << f3 << '\n';

}