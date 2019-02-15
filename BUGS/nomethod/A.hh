#pragma once
#include "GLWin.hh"
class A : public GLWin {
public:
	A() : GLWin(1000,800, "test", "tut01.vs", "tut01.fs", Color(0,0,0)) {}
	void setup() override;
	void draw() const override;
};
