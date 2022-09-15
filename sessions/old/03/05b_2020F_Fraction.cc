#include <iostream>
using namespace std;
int x;

class Fraction {
private:
  int num, den;
public: // this is what everyone in the program can see
  Fraction(int num, int den) : num(num), den(den) {} 

  void print() const { // method   C++ term: member function
    cout << num << '/' << den;                    // 1/2
  }

  void setNum(int n) {
      num = n;
  }
  void setDen(int d) {
      den = d;
  }
  /*
     this->                 b.
           num                  num
           den                  den

           1                    1           1*3 + 1*2
           -        +           -       =   -
           2                    3           2*3

   1. Create a new object to hold the answer
   2. set num and den appropriately
   3. return the object

  */
  Fraction add(Fraction b) const { // const means "I promise not to change this"
    //const Fraction* this; // this is read only
       // when we add fraction this to fraction b we get a new fraction
    Fraction ans(num*b.den + b.num*den, den * b.den);
    return ans;
  }



};

int main() {
  int x = 3,  y = 4;
  const Fraction a(1,2); // 1/2
  
  a.print(); // internally, this is :print(, )
  cout << '\n';
  Fraction b(1,3); // 1/3
  b.print();
  cout << '\n';
  b.setNum(4);
  Fraction c = a.add(b);
  c.print();
  cout << '\n';
  //Fraction b(1,3);
  //Fraction c = a + b;
  //cout << a;
}

