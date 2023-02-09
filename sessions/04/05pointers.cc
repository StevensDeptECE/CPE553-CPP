#include <iostream>
using namespace std;

int main() {
    int a = 3;
    //const int b;
    const int c = 4;

    a = 99;
//    c = 99;

    int & r = a; // r is a reference to int initialized to a
    // r is an alias to a
    a = 44;
    r = 55;
    cout << a; // a is 55
    //int& r2 = c;
    //c = 5;
    //r2 = 6;

    const int& r2 = c; // r2 is a READ ONLY reference
    //r2 = 99;
    const int& r3 = a;
    a++;
    cout << r3;
}