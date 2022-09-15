#include "A.hh"
#include "B.hh"
#include "C.hh"

int main() {
	//	A a1; // illegal: A is ABSTRACT
	B b1;
	C c1;
	A* ap= & b1;
	ap->f();
	B* bp = & b1;
	bp->f();
	//ILLEGAL	B* bp = & c1;

	A* list[3];
	list[0] = &b1;
	list[1] = &c1;

	B list[10];
}
 

