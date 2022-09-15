#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d) : num(n), den(d) {
		if (d == 0) {
      throw "Div by zero";
		}
	}
	friend ostream& operator <<(ostream& s, const Fraction& f) {
		return s << f.num << "/" << f.den;
	}
};

int mysqrt(int x) {
  if (x < 0)
		throw "AAAAAAAgh";
	return sqrt(x);
}

int main() {
	try {
		//		int y = mysqrt(-5);
		Fraction a(1,2); // 1/2
		Fraction c(1,0); // 1/0 ???
		cout << a << '\n';
	} catch(const char*msg ) {
		cerr << msg << '\n';
	}

}
