#include <iostream>
#include <string>
using namespace std;

///    a.b     member b inside the object a
//   A::b      member b inside the class A


template<typename T, typename Key>
void sort(T a[], uint32_t len, Key T::*key) {
    for (int j = 0; j < len-1; j++) {
      for (int i = 0; i < len-1; i++)
        if (a[i].*key > a[i+1].*key) {
            swap(a[i], a[i+1]);
        }
  }
}

template<typename T>
void print(const T a[], uint32_t len) {
    for (int i = 0; i < len; i++)
      cout << a[i].name << "," << a[i].age << ' ';
    cout << '\n';
}

class Elephant {
public:
  string name;
  int age;
  friend bool operator >(const Elephant& a, const Elephant& b) {
    return a.age > b.age;
  }
};
int main() {
  Elephant e[] = { {"Fred", 3}, {"Alice", 19}, {"Tom", 11} };
  constexpr int n = sizeof(e)/sizeof(Elephant);
  sort(e, n, &Elephant::name);
  sort(e, n, &Elephant::age);
  print(e, n);
}