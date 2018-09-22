#include <iostream>
using namespace std;

class Fraction {
private:
  int num, den;
public:
  Fraction() : Fraction(0,1) {}
	//	Fraction(int num) : num(num), den(1) {}
	Fraction(int num) : Fraction(num,1) {}
	Fraction(int num, int den) : num(num), den(den) {
	}
	void print() const {
		cout << num << "/" << den;
	}
  Fraction add(Fraction r)const {   // 1/2 + 1/3 = 5/6
    Fraction ans(this->num * r.den + r.num * this->den, this->den * r.den);
		return ans;
	}
  Fraction add2(Fraction r)const {   // 1/2 + 1/3 = 5/6
    Fraction ans(num * r.den + r.num * den, den * r.den);
		return ans;
	}
  Fraction add3(Fraction r)const {   // 1/2 + 1/3 = 5/6
		return Fraction(num * r.den + r.num * den, den * r.den);
	}
};

int main() {
	Fraction f1;
	const Fraction f2(1,2);
	Fraction f3(5);
	Fraction f4(1,3);
	f1.print();    // 0/1
	f2.print();    // 1/2
	f3 = f2.add(f4); // 1/2 + 1/3 = 5/6
	f3.print();
}
