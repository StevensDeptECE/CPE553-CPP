#include <iostream>
#include <string>
using namespace std;

class Trace {
private:
  const string& func;
  static int times; // declaration (extern)
public:
  Trace(const string& func) : func(func) {
    times++;
    cout  << "Entering function " << func << "\n";
  }
  ~Trace() {
    cout << "Leaving function " << func << "\n";
  }
  static int count() { return times; }
};

int Trace::times = 0; // definition

void g() {
  Trace t("g");
}

void f() {
  Trace t("f");
  g();
}

int main() {
  for (int i = 0; i < 10; i++)
    f();
  cout << Trace::count() << '\n';

}
