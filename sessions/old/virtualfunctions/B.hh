#pragma once
#include "A.hh"

class B : public A {
private:
	int y;
	int z[10];
public:
	void f() override;
};
