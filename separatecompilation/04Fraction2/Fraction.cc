#include "Fraction.hh"
using namespace std;

/*
 you cannot generate an inline function here, or in main.cc
 it will not find this function!
*/
Fraction operator +(Fraction a, Fraction b) {
  return Fraction(a.num*b.den +b.num*a.den, a.den*b.den);
}


// a horrendous function that does nothing in 2 giant loops
void Fraction::f(){
	for (int i = 0; i < 1000000; i++) {
		num++;
		den--;
	}
	for (int i = 0; i < 1000000; i++) {
		num--;
		den++;
	}
}

ostream& operator <<(ostream& s, Fraction f){
  return s << f.num << '/' << f.den;
}
