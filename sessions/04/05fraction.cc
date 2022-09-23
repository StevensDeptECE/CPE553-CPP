#include <iostream>
using namespace std;

class fraction {
private:
  int num;
  int den;
public:
  fraction(int n = 0, int d = 1) {
    num = n;
    den = d;
  }

/* intrinsic 1st parameter this points to the object
   this->               right.
     num =1               num=1             1*3+1*2 = 5
     den =2               den=3             2*3



*/
  friend fraction add(const fraction& a, const fraction& b) {
    fraction ans(a.num*b.den + a.num*b.den), a.den*b.den);
    return ans;
  } 

  fraction add(const fraction& right) {
    fraction ans(this->num*right.den + right.num*this->den), this->den*right.den);
    return ans;
  } 

  static fraction add(const fraction& a, const fraction& b) {
    fraction ans(a.num*b.den + b.num*a.den), a.den*b.den);
    return ans;
  }

  friend fraction operator +(const fraction& a, const fraction& b) {
    fraction ans(a.num*b.den + b.num*a.den), a.den*b.den);
    return ans;
  }

  // this is binary -
  friend fraction operator -(const fraction& a, const fraction& b) {
    return fraction(0,0); // TODO: left to the reader
  }

  // this is unary -
  friend fraction operator -(const fraction& a) {
    return fraction(-a.num, a.den); // calling the constructor craetes a variable with NO NAME
  }

  friend ostream& operator <<(ostream& s, const fraction& f) {
    return s << f.num << "/" << f.den;
  }
  friend istream& operator >>(istream& s, fraction& f) {
    return s >> f.num >> f.den;
  }

};

int main() {
  const fraction a; //  0/1
  fraction b(1,2);  //   1/2
  fraction c(1,3);
  cout << a << "\n";
  fraction d = b.add(c); // regular method
  fraction e = fraction::add(b,c); // static function
  fraction f = b + c; // friend binary operator
  fraction g = add(b,c); // friend function
  cout << "d=" << d << '\n';
  cout << "e=" << e << '\n';
  cout << "f=" << f << '\n';
  cin >> b; // 1  2 notice, no "/" separating on input! C++ has a hard time with that.
}