#include <iostream>
#include <fstream>
using namespace std;

class Fraction {
private:
	int num, den;
public:
	Fraction(int n, int d) : num(n), den(d) {}
	friend ostream& operator <<(ostream& s, Fraction f) {
		s << f.num << '/' << f.den;
		return s;
	}
};

int main() {
	Fraction a(1,2);
	cout << a << "\n";  // (2 + 3) + 4
	ofstream f("test.dat");
	f << a << '\n';
}
		
