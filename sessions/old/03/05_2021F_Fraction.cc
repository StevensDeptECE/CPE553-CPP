#include <iostream>
using namespace std;

class fraction {
private:

public:
  int  num, den;
  fraction(int n = 0, int d = 1) : num(n), den(d) {
	}
	friend fraction operator +(fraction a, fraction b) {
		return fraction(a.num*b.den+b.num*a.den, a.den*b.den);
	}

	friend ostream& operator <<(ostream& s, Fraction f) {
		return s << f.num << '/' << f.den;
	}
};

int main() {
	ofstream file("test.dat");
	fraction f1(1,2);
	fraction f2(1,3);
 	fraction f3 = f1 + f2;
	cout << f3 << '\n';
	fraction f4 = -f1;
	file << f4 << '\n';
}
