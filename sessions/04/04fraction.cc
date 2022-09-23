#include <iostream>
using namespace std;

class fraction {
private:
  int num;
  int den;
public:
  fraction() {
    num = 0;
    den = 1;
  }
  fraction(int n) { // fraction(3)  3/1
    num = n;
    den = 1;
  }

  fraction(int n, int d) {
    num = n;
    den = d;
  }

  // this points to the object
  void print() {
    cout << this->num << "/" << den;
  }
};

int main() {
  fraction a; //  0/1
  fraction b(1,2);  //   1/2
  a.print();
  cout << "\n\n";
  b.print();
  cout << "\n\n";

//  fraction c = a + b; // c = a.add(b);   c = add(a,b);

}