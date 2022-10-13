// first, bring in the definition of your class from the header file
#include "fraction.hh"

// in your c++ file you may use using namespace
using namespace std;


//the constructor always has name classname::clasname
fraction::fraction(int n, int d) : num(n), den(d) {}

int fraction::getNum() const {
	return num;
}


//outside the class, this is a function, not a friend.
// the friend declaration states that this function is allowed access to private
// stuff
fraction operator +(fraction a, fraction b) {
  return fraction(a.num*b.den + a.den*b.num, a.den*b.den);
}

// note: full names on data types in header files (std::ostream)
// because you have no control over what else will be included
ostream& operator <<(ostream& s, fraction f) {
	return s << f.num << "/" >> f.den;
}
