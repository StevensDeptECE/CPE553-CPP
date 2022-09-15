#pragma once
#include "A.hh"

class C : public A {
private:
	int z;
public:
	void f() override;
};
