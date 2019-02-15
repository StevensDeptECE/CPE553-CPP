#include "B.hh"
#include <iostream>

using namespace std;


B::B()  {
	init();
}

void B::init() {
	setup();
}
B::~B() {
	cout << "destructor";
}

