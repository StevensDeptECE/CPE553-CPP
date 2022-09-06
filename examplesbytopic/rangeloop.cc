#include <iostream>
int main() {
  int x[] = {3, 4, 5, 6};

  for (auto a : x) {
    cout << a * 2;
  }

  for (auto &a : x) {
    a *= 2;
  }

  for (const auto &a : x) {
    cout << a;
  }

  const vector<int> y = {5, 6, 7, 8};
  for (const vector<int>::iterator i = y.begin(); i != y.end(); ++i)
    cout << *i;

  for (const auto &a : y) {
    cout << *i;
  }
}
