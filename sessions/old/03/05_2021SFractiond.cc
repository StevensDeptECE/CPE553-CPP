#include <iostream>
using namespace std;

class Fraction {
private:
  int num, den; // numerator, denominator
public:
  Fraction(int num = 0, int den = 1) : num(num), den(den) {}
  void print() const { // this method promises NOT TO CHANGE the object (readonly)
    cout << this->num << '/' << this->den;
  }
  Fraction operator +(Fraction right) const {
    return Fraction(num*right.den + right.num*den, den*right.den );
  }
  Fraction operator -(Fraction right) const {
    return Fraction(num*right.den - right.num*den, den*right.den );
  }
  Fraction operator *(Fraction right) const { //  1/2 * 2/1 = 2/2 
    return Fraction(num*right.num, den*right.den );
  }
  Fraction operator -() const {
    return Fraction(-num, den );
  }
};


int main() {
  const Fraction a(1,2);  // 1/2
  const Fraction b(1,3);  // 1/3
  const Fraction c;
  const Fraction d(3); // 
  const Fraction e = a + b;
  const Fraction f = a - b;
  const Fraction g = a * b;
  const Fraction h = -a;
  
  
  e.print();  // 1/2  printinternal(pointer to a)
  cout << '\n';
}

