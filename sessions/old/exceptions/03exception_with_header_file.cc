#include "Ex.hh"
using namespace std;

class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d) : num(n), den(d) {
		if (d == 0) {
			throw Ex1("Div By Zero");
		}
	}
	friend ostream& operator <<(ostream& s, const Fraction& f) {
		return s << f.num << "/" << f.den;
	}
};


int main() {
	try {
		Fraction a(1,2); // 1/2
		Fraction c(1,0); // 1/0 ???
		cout << a << '\n';
	} catch(const Ex& e ) {
		cerr << e << '\n';
	}

}
