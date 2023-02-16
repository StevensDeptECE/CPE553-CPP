#include <iostream>
#include <cstdint>
using namespace std;

class fraction {
private:
  int num,den;
public:
  fraction(int n = 0, int d = 1) : num(n), den(d) {}
  fraction operator +(const fraction& right) const {
    return fraction(num*right.den + right.num*den, den* right.den  );
  }
  friend fraction operator -(const fraction& a, const fraction& b);
  friend fraction sub(const fraction& a, const fraction& b);
  friend fraction operator *(const fraction& a, const fraction& b) {
    return fraction(a.num*b.num, a.den* b.den);
  }
};
fraction operator -(const fraction& a, const fraction& b) {
  return fraction(a.num*b.den - b.num*a.den, a.den* b.den  );
}
fraction sub(const fraction& a, const fraction& b) {
  return fraction(a.num*b.den - b.num*a.den, a.den* b.den  );
}
  

int main() {
    f(uint64_t(2));

    f(3.5);
    f(44ULL);


    const fraction a(1,2);      // 0/1
    fraction b(1,3); // 1/2
    fraction c = a + b;
    fraction d = a - b;
    fraction e = sub(a,b);
    cout << c << "   " << d << '\n';

    fraction f = a + 3; // a + fraction(3)
    fraction g = fraction(3) + a; // symmetrically DOES NOT WORK
    fraction h = a - 3;
    fraction i = 3 - a;




}