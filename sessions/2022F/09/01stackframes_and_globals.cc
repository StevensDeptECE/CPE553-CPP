#include <iostream>
using namespace std;

int a; // globals are all initialized to binary 0
bool b; // b is false (binary 0)

namespace stevens {
  int x; // stevens::x
  namespace cpe553 {
    int x;  // stevens::cpe553::x
    // how about
    class AAA{
    };
  };

};

namespace stevens {
  uint32_t alice;
};


struct Hello {
    int a;
    uint64_t b; 
    float c; 
};

Hello h; // h.a = 0 h.b = 0  h.c = 0.0
void f(int x) {
  int a = 22;
  int b = 35;
  int c = 7;
  int y[100];

}
int main() {
    int a;
    int arr[20];
    f(3);
    cout << a << '\n';
    cout << ::a << '\n';
}