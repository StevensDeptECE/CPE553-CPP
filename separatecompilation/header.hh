#pragma once

#include <iostream>

class my_obj {
public:

	my_obj();
	friend std::ostream& operator <<(std::ostream& s, my_obj x);

	void f();
};
