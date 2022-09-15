#include <iostream>
using namespace std;
int x;

class Fraction {
private:
  int num, den;
public: // this is what everyone in the program can see
  Fraction(int n, int d) { // constructor
    num = n;
    den = d;
    cout << "In constructor: " << num <<  "," << den << '\n';
  }
#if 0
/*
  Fraction(int num, int den) { // constructor
    this->num = num;
    this->den = den;
    cout << "In constructor: " << num <<  "," << den << '\n';
  } 

  Fraction(int num, int den) : num(num), den(den) {
    cout << "In constructor: " << num <<  "," << den << '\n';
  } 
*/
#endif
  void print() { // method   C++ term: member function
    cout << num << '/' << den;                    // 1/2
  }

};

int main() {
  int x = 3,  y = 4;
  Fraction a(1,2); // 1/2
  
  a.print(); // internally, this is :print(, )
  Fraction b(1,3); // 1/3
  b.print();
  //Fraction b(1,3);
  //Fraction c = a + b;
  //cout << a;
}

