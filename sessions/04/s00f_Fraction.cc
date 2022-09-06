#include <iostream>
using namespace std;
class Fraction {
private:
	int num, den;
public:
	Fraction(int n = 0, int d = 1) : num(n), den(d) {}
	void add(); // methods have the right to access private components
  friend ostream& operator <<(ostream& s, Fraction f );
};

ostream& operator <<(ostream& s, Fraction f ) {
	s << f.num << "/" << f.den;
  return s;
}

int main() {
	Fraction f1(1,2);
	Fraction f2(3);
	Fraction f3;
	cout << f1 << '\n';
}
