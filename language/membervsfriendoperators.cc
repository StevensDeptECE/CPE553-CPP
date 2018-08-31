#include <iostream>
using namespace std;

//using friend
class Fraction {
	friend Fraction operator +(Fraction left, Fraction right);
	friend Fraction operator -(Fraction a);
};

//using member operators
class Fraction2 {
	Fraction2 add(Fraction2 right);
	
	Fraction2 operator +(Fraction2 right);
	Fraction2 operator -();
};

int main() {
	Fraction a(1,2);
	Fraction b(1,3);
	Fraction c = a + b; // calls operator +, either a member or a friend
	Fraction d = -a; // calls operator +, either a member or a friend


	Fraction2 a(1,2);
	Fraction2 b(1,3);
	Fraction2 c = a.add(b); // this points to a
	Fraction2 d = a + b; // calls operator +, either a member or a friend
	Fraction2 e = -a; // calls operator +, either a member or a friend
}
