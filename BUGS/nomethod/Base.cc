#include "Base.hh"
#include <iostream>

using namespace std;


Base::Base()  {
	setup();
}

Base::~Base() {
	cout << "Base::destructor";
}

