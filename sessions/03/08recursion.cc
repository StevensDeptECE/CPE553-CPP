#include <iostream>

// recursive function: calls itself
// must end (base case)
int f(int x) {
    std::cout << x << '\n';
    return f(x-1);
}

int main() {
    std::cout << f(5) << '\n';

}