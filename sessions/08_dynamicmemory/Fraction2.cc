#include <iostream>
using namespace std;
class Ex {
private:
  int linenum;
  const char * filename;
public:
  Ex(int linenum, const char* filename)
    : linenum(linenum), filename(filename) {}
  friend ostream& operator <<(ostream& s, const Ex& dbz) {
    return s << dbz.filename << ": " << dbz.linenum;
  }
};

class DivByZero : public Ex {
public:
  DivByZero(int linenum, const char* filename) : Ex(linenum, filename){}
  friend ostream& operator <<(ostream& s, const DivByZero& dbz) {
    return s << "Divide by zero " << (Ex&)dbz;
  }
};


class Fraction {
private:
  int num, den;

  int gcd(int a, int b) { // Euclid  gcd(a,0) == a  gcd(b, a % b)
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
public:
  Fraction(int n, int d) : num(n), den(d) {
    if (d == 0) {
      throw DivByZero(__LINE__, __FILE__);
    }
    int g = gcd(n,d);
    if (g > 1) {
      num /= g;
      den /= g;
    }
  }
  friend Fraction operator +(Fraction a, Fraction b) {
    return Fraction(a.num*b.den+a.den*b.num, a.den*b.den);
  }

  friend Fraction operator /(Fraction a, Fraction b) {
    return Fraction(a.num*b.den, a.den*b.num);
  }

};

int main() {
  try { 
    Fraction a(1,2); // 1/2
    Fraction b(1,2); // 1/3
    Fraction c = a + b; // 2/4   -->  1/2
    
    Fraction d(0,1);
    Fraction e = c / d; 
  } catch (DivByZero e) {
    cout << e << '\n';
  }

}
