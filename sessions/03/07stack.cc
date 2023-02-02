#include <iostream>

int h(int a) {
    return a*a;
}

int g(int x) {
    return h(x*2);
}

int f(int x) {
    return g(x + 1);
}

int main() {
    int a[100] = {3}; // 400 bytes
    std::cout << f(10) << '\n';



}