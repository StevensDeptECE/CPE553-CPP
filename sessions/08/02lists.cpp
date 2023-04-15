#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
  vector<int> a;
  vector<string> b;  
  for (int i = 0; i < 10; i++)
    a.push_back(i); // add to end
  for (int i = 0; i < 10; i++)
    cout << a[i] << ' ';
  cout << '\n';

  for (auto x : a)
    cout << x << ' ';
  cout << '\n';

  for (vector<int>::iterator i = a.begin(); i != a.end(); ++i) {
    cout << *i;
  }

  for (vector<int>::iterator i = a.begin(); i != a.end(); ++i) {
    *i *= 3;
  }

  for (auto& x : a)
    x = x - 3; // subtract 3 from each element
//    x = 9; // set every element to 9!

  list<int> b;
  b.push_back(3);
  b.push_back(1);
  b.push_back(4);

  for (list<int>::iterator i = a.begin(); i != a.end(); ++i) {
    cout << *i;
  }

  for (auto x : b)
    cout << x;
}