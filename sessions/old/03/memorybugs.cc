#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int y = 5;
    char s[5];
    int x = 3;
    char t[18] = {0};
    char buf[256];
    cin >> buf;

    cout << "x=" << x << " y=" << y << '\n';
    strcpy(s, buf);
    cout << "x=" << x << " y=" << y << '\n';
}