#include <iostream>
using namespace std;

class Fraction {
public:
	// always prefer to use initializer list
  Fraction(int n, int d) : num(n), den(d) {  }
	void print() const {
		cout << num << "/" << den;
	}
	friend void print(Fraction f);
private:  	
	int num, den;
};

void print(Fraction f) {
	cout << f.num << "/" << f.den;
}

int main() {
	const Fraction a(1, 2); // 1/2
	Fraction b(1, 3);
	Fraction c(-6, 5); // -6/5
	print(a);
	a.print();
	//	cout << a;
	
}
