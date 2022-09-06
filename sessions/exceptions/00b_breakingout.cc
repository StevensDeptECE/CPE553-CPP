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

void g() {
	Fraction a(1,0);
}
void f() {
	cout << "now in f!\n";
	g();
	cout << "never gets here...\n";
}

void h() {
	Fraction a(1,2);
}
int main() {
	try {
		h();
		f();
	} catch(const char*msg ) {
		cerr << msg << '\n';
	}

}
