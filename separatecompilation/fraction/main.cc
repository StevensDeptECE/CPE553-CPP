#include "fraction.hh"

using namespace std;
int main() {
    const fraction f1(1,2); //  1/2
    fraction f2(1,3); // 1/3
    fraction f3 = f1 + f2; // implement as a member function
    fraction f4 = -f1;   // implement as member function

    cout << f4 << '\n';
    cout << f1.getNum() << '\n';
    cout << f1.getDen() << '\n';
    f2.setNum(13);

}