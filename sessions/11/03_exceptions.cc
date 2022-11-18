#include <iostream>
#include <exception>
using namespace std;

int f() {
    int x = 5;
    int y = 0;

    throw 5;

    int*p = new int[10000000000];

    throw exception();

    if (y == 0)
      throw "tantrum";
    return x / y;
    int a[10] = {5, 3, 1};
    for (int i = 0; i < 10; i++)
      if (a[i] == 0)  // Stroustrup sez "don't do this!"
        throw "found the end";

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