#pragma once
#include "Base.hh"

class A : public Base {
public:
	A() {}
	void setup() override;
	void draw() const override;
};
