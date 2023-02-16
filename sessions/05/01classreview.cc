#include <iostream>
#include <cstdint>
using namespace std;

int f(uint64_t x) { return x*x; }
double f(double x) { return x+3; }



class fraction {
public:
  int num,den;
public:
  fraction(int n = 0, int d = 1) : num(n), den(d) {}
#if 0
  fraction(int num, int den) : num(num), den(den) {}
  fraction() : num(0), den(1) {}
  fraction(int n) : num(n), den(1) {}
  #endif
  fraction add(const fraction& right) const {
    return fraction(num*right.den + right.num*den, den* right.den  );
  }
  //fraction operator +(const fraction& right) const {
  //  return fraction(num*right.den + right.num*den, den* right.den  );
  //}
  
  fraction operator +(const fraction& right) const {
    return this->add(right);
  }
  

  static fraction add(const fraction& a, const fraction& b) {
    return fraction(a.num*b.den + b.num*a.den, a.den* b.den  );
  }
};


int main() {
    f(uint64_t(2));

    f(3.5);
    f(44ULL);


    const fraction a;      // 0/1
    fraction b(1,2); // 1/2
    fraction c(3);   // 3/1 
//    fraction d();  This declares a function d that returns fraction
    fraction d = a.add(b);
    fraction e = a + b;
    fraction e2 = a.operator +(b);
    fraction f = fraction::add(a,b); // static function
}