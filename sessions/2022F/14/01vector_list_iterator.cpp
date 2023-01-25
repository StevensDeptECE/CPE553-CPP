#include <iostream>
#include <vector>
#include <list>
using namespace std;

// difference between postinc: operator ++(string )   x++
// preinc: operator ++()   ++x
int main() {
    vector<int> a;
    a.reserve(1000);
    for (int i = 0; i < 1000; i++)
      a.push_back(i);

    for (int i = 0; i < a.size(); i++)
      a[i];

    for (vector<int>::iterator i = a.begin(); i != a.end(); ++i)
      cout << *i; // operator *() means the value at this location
    
    for (auto x : a)
      cout << x;

    list b;
    for (int i = 0; i < n; i++)
      b.push_back(i);

    // this is good for an array, VERY BAD for a list
    //for (int i = 0; i < a.size(); i++)
    //  b[i];

    for (list<int>::iterator i = b.begin(); i != b.end(); ++i)
      *i *= 2;
    for (list<int>::const_iterator i = b.begin(); i != b.end(); ++i)
      cout << *i;

    for (auto x : b) {
      cout << x << ' ';
    }
    for (auto& x : b) {
      x  = 99;
    }

    vector<const int> c = {1, 2, 3};
    c.push_back(4);

    const vector<int> d = {1,2,3};
    for (vector<int>::const_iterator i = d.begin(); i != d.end(); ++i) 
       *i = 5;



   
}