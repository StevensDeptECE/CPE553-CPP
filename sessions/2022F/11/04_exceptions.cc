#include <iostream>
#include <exception>
using namespace std;
/*
What exceptions should I write?

1. What does the program do in response to exceptions?
   a. Die
   b. change something, and retry, or just wait and retry
   c. post a message and keep on going

  only have as many different exceptions as you have different actions you want to take
  (polymorphism)

*/




int h() {

    throw "test";
}

int g() {
//    Elephant e("Fred");
    int a[10];
    h();
    return 5;
}

int f() {
    return g();
}


int main() {
    try {
        int answer = f();

    }catch(const char msg[]) {
        cerr << msg << '\n';
    } catch(const exception& e) {
        cerr << e.what();
    } catch (...) {
        cerr << "something happened!!!\n";
    } 
}