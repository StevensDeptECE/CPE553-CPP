#include <iostream>
#include "A.hh"
#include "B.hh"
using namespace std;

int main() {
	A a1;      // should print A::setup()
	a1.draw(); // should print A::draw()
	B b1;      // should print B::setup()
	b1.draw(); // should print B::draw()
	// should print Base::destructor
}
