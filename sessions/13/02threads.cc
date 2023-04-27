#include <thread>
#include <iostream>
#include <unistd.h>

using namespace std;

void f() {
    for (;;) {
        cout << "hello";
        usleep(100000);
    }
}

void g() {
    for (;;) {
      cout << "bye";
      usleep(253000);
    }
}

int main() {
    thread t1(f);
    thread t2(g);
    t1.join();
    t2.join();
}