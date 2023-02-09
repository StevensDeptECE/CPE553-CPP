#include <iostream>
#include <fstream>
using namespace std;

int x;
void f() { int x; x = x + 1; }

class A {


};


class fraction {
public:
  int num;
  int den;
public:
// a constructor is a function with the same name as the class
// it is an error to specify a return type on a constructor
  fraction(int n, int d) : num(n), den(d) {
    num = n;
    den = d;
  }
  void print() const { // method  c++: member function
    cout << num << "/" << den;
  }
  friend ostream& operator <<(ostream& s, const fraction& f) {
    return s << f.num << "/" << f.den;
  }
};

int main() {
    int x = 2 + 3 + 9;
  fraction a(1,2); // create a variable a of type fraction
  a.print(); // send a message print to object a
  cout << '\n';
  cout << a << '\n';
ofstream f("test.dat");
  f << a << '\n';
  const fraction b(1,3);
  b.print(); 

//  fraction b(1,3);
//  fraction c = a + b;  
//  c.print();
//  cout << a;
}