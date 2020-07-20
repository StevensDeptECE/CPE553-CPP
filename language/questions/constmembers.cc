#include <iostream>
using namespace std;

const double pi = 3.13159265358979;
class ConstMember {
private:
  const int x;
public:
  ConstMember(int x) : x(x) {}
  void inc() {
    ++*(int*)&x;
  }
  void print() const {
    cout << x << endl;
  }
};

int main() {
  ConstMember cm(2);
  cm.print();
  cm.inc();
  cm.print();
  cout << pi << '\n';
  *(double*)&pi = 4;
  cout << pi << '\n';
}
