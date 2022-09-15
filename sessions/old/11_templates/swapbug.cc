#include <iostream>
using namespace std;

template<typename T>
void myswap(T& a, T& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 2, b = 3;
    myswap(a,b);
    cout << a << " " << b << '\n';

    double c = 2.5, d = 3.5;
    myswap(c,d);
    cout << c << " " << d << '\n';

}