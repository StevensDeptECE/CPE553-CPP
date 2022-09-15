#include <iostream>

using namespace std;
class fraction {
public:
	fraction(int num, int den) : num(num), den(den) {
	}

  void print() const {
		cout << this-> num << "/" << den;
	}

	
	friend ostream& operator <<(ostream& s, fraction f);
	friend fraction add(fraction a, fraction b);
  fraction add(fraction r) {
		return fraction(this->num*r.den + r.num*this->den  , den * r.den );
	}
private:
  const int num, den;	
};

// a.num = 1 a.den = 2    b.num = 1  b.den = 3
fraction add(fraction a, fraction b) {
	return fraction(a.num*b.den + b.num*a.den  , a.den * b.den );
}

ostream& operator <<(ostream& s, fraction f) {
	return s << f.num << "/" << f.den;
}

int main() {
	const fraction a(1,2); // 1/2
	const fraction b(1,3); // 1/3
  a.print();
	const fraction c = a + b;
	const fraction d = add(a,b);
	const fraction e = a.add(b);
	cout << a << '\n';
  int v = 1 << 3; // 0000000000001000
	
}
