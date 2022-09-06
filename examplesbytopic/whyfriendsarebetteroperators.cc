#include <iostream>
using namespace std;

//using friend
class Fraction {
private:
	int num, den;
public:
  Fraction(int num, int den) : num(num), den(den) {}
  Fraction(int num) : num(num), den(1) {}
	
	friend Fraction operator +(Fraction left, Fraction right);
	friend Fraction operator -(Fraction a);
};

//using member operators
class Fraction2 {
private:
	int num, den;
public:
  Fraction2(int num, int den) : num(num), den(den) {}
  Fraction2(int num) : num(num), den(1) {}

	Fraction2 operator +(Fraction2 right);
	Fraction2 operator -();
};

int main() {
	Fraction a(1,2);
	Fraction x(3); // 3/1
	Fraction b(1,3);
	Fraction c = a + x;
	Fraction d = a + 3; // this automatically calls Fraction(3)
  Fraction e = 3 + a; // this automatically calls Fraction(3)

	Fraction2 a(1,2);
	Fraction2 b(1,3);
	Fraction c = a + b;
	Fraction d = a + 3; // this automatically calls Fraction(3)
  Fraction e = 3 + a; // FAILS
}
