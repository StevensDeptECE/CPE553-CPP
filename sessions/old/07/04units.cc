#include <iostream>
using namespace std;

class Unit {
  int length, mass, time;
  double conv;
public:

};

int main() {
  Unit a(5, "kg");
  Unit b(2, "m");
  Unit c(3, "second");
  Unit d(2.5, "feet");
  cout << a + b << '\n'; // error!
  Unit diamons(1e8, "$/kg");
  cout << d / c << '\n'; // speed

}  
}
