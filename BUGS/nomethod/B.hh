#pragma once
#include "Base.hh"

class B : public Base {
public:
	B() {}
	void setup() override;
	void draw() const override;
};
