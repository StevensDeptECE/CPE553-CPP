#include <iostream>
using namespace std;
class A {
private:
    uint64_t x;
};

class B {
private:
    uint64_t x;
public:
    virtual void f() {}
};

int main() {
    A a1;
    B b1;

    for (int i = 0; i < 10; i++)
        ;

}