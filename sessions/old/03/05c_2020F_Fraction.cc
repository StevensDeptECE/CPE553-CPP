#include <iostream>
using namespace std;
int x;

class Fraction {
private:
  int num, den;
public: // this is what everyone in the program can see
  Fraction(int num, int den) : num(num), den(den) {} 

  Fraction operator +(Fraction b) const { // const means "I promise not to change this"
    //const Fraction* this; // this is read only
       // when we add fraction this to fraction b we get a new fraction
    Fraction ans(num*b.den + b.num*den, den * b.den);
    return ans;
  }
  
  friend ostream& operator <<(ostream& s, const Fraction& f);
  friend void f();
};

void f() {
    Fraction a(1,2);
    a.num = 19;
}

ostream& operator <<(ostream& s, const Fraction& f) {
  return s << f.num << "/" << f.den;
}
/*
    Rules for operator overloading
    1. You may not redefine what is already defined
            2+2  int+int
            int operator +(int a, int b) ; // illegal!
    2. You may not invent new operators
        +, -, *, /, ...  +++ NO
    3. Precedence remains the same
        Imagine the chaos!
        int a = 2 + 3 * 4;
        Fraction x = y + z*w; // this MUST work the same way
*/



int main() {
  int x = 3,  y = 4;
  const Fraction a(1,2); // 1/2
  Fraction b(1,3); // 1/3
  Fraction c = a + b; // a.operator+(b)
  int z = 2 + 3 + 4 + 5;
  cout << c << '\n';
}

