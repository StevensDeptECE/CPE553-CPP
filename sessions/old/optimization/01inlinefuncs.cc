#include <iostream>
using namespace std;

int add(int a, int b);

class Fraction {
private:
  int num,den;
public:
  Fraction(int num = 0, int den = 1) : num(num), den(den){}
  Fraction operator +(const Fraction& o) const {
    return Fraction(num * o.den + o.num * den, den * o.den);
  }
  Fraction operator *(const Fraction& o) const {
    return Fraction(num * o.num, den * o.den);
  }
  friend ostream& operator <<(ostream& s, const Fraction& f) {
      cout << f.num << '/' << f.den;
      return s;
  }
};

int main() {
  //cout << add(2,3) << '\n';  
  //cout << add(5,4) << '\n';
  const int n = 1000000000; // 100 million times
  Fraction c;
  for (int i = 0; i < n; i++) {  
    Fraction a(1,2);
    Fraction b(1,3);
    c = c + (a+b);
  }
  cout << c << '\n';
}