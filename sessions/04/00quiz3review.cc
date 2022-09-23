#include <iostream>
using namespace std;
void datatypes() {
    double a = 3 / 2; // a = 1.0
    int b = 3.0 / 2 * 2; // b =3 
    uint32_t c = -1; // 111111111111111111111111111111
    c++;             // 000000000000000000000000000001
                     // ==============================
                     //1000000000000000000000000000000
    cout << c << '\n';

}

void loops() {
  
}

void f(int a) {
    a = 17;
}
int g(int a, int b) {
    int sum = (a + b) / 2;
    for (int i = a; i <= b; i+= 2) {
      if (i % 17 == 0) {
        sum++;
      }
    }
    return sum;
}

// pass by reference
void zero(double& a, double& b, double& c) {
    a = 0;
    b = 0;
    c = 0;
}

int main() {
  datatypes();
  int a;
    f(a);
  cout << a;
  uint32_t b = 2, c = 3;
  int d = g(b, c); // (2+3)/2 = 2
  double x= 2, y = 3.0, z = 4.0
  zero(x,y,z);
  cout << x << y  << z;
  loops();

  
}