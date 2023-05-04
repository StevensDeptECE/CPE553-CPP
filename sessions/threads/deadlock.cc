#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;

mutex a;
mutex b;

void f() {
    a.lock();
    sleep(10);
    b.lock();
}

void g() {
    b.lock();
    sleep(10);
    a.lock();
}

int main() {
    thread t1(f);
    thread t2(g);
    t1.join();
    t2.join();
    // should be deadlock! threads will never finish

}