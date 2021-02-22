#include <iostream>
using namespace std;

class Fraction {
private:
  int num, den; // numerator, denominator
public:
  Fraction(int n, int d) {
    num = n;
    den = d;
  }
  Fraction(int n) {
    num = n;
    den = 1;
  }
  Fraction() {
    num = 0;
    den = 1;
  }
  void print() const { // this method promises NOT TO CHANGE the object (readonly)
    cout << this->num << '/' << this->den;
  }

#if 0
  // lefthand side is this->num, this->den   righthand side is right.num  right.den
  Fraction add(Fraction right) {
    // this is the object to whom the message is being sent     1/2 + 1/3 = /6
    Fraction ans(this->num*right.den + right.num*this->den, this->den*right.den );
    return ans;
  }

  Fraction add(Fraction right) {
    // this is the object to whom the message is being sent     1/2 + 1/3 = /6
    return Fraction(this->num*right.den + right.num*this->den, this->den*right.den );
  }
  Fraction operator +(Fraction right) const {
    // this is the object to whom the message is being sent     1/2 + 1/3 = /6
    return Fraction(num*right.den + right.num*den, den*right.den );
  }
#endif
  Fraction add(Fraction right) const {
    // this is the object to whom the message is being sent     1/2 + 1/3 = /6
    return Fraction(num*right.den + right.num*den, den*right.den );
  }
  friend Fraction operator +(Fraction left, Fraction right);
};

Fraction operator +(Fraction left, Fraction right) {
  return Fraction(left.num*right.den + right.num*left.den, left.den*right.den );
}

int main() {
  const Fraction a(1,2);  // 1/2
  Fraction b(1,3);  // 1/3
  Fraction c;
  Fraction d(3); // 
  //Fraction e(); // this is not an object. It is a function that returns Fraction
  Fraction f1 = a.add(b);
  Fraction f2 = a + b;
  a.print();  // 1/2  printinternal(pointer to a)
  cout << '\n';
  b.print();
  cout << '\n';
  //e.print();
  const Fraction f(3,4);
  f.print();
}

