#include <iostream>
#include <fstream>
using namespace std;

class fraction {
public:
  int num;
  int den;
public:
  fraction(int n, int d) : num(n), den(d) { }
  friend ostream& operator <<(ostream& s, const fraction& f) {
    return s << f.num << "/" << f.den;
  }
  // lefthand side is this
  // 1/2 + 1/3 = 5/6
  // this->num       right.num
  // this->den       right.den
  fraction add(const fraction& right) const {
    fraction ans(num*right.den + right.num*den,
       this->den * right.den);
    return ans;
  }
  fraction add2(fraction right) const {
    return fraction(num*right.den + right.num*den, den * right.den);
  }
  fraction operator +(const fraction& right) const {
    return fraction(num*right.den + right.num*den, den * right.den);
  }

};

int main() {
  const fraction a(2,4); // create a variable a of type fraction
  const fraction b(2,4);
  fraction c = a.add(b);
  fraction d = a.add2(b);
  fraction e = a + b;
  cout << c << '\n';
  cout << d << '\n';
  cout << e << '\n';
}