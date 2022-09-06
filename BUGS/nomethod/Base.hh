#pragma once

class Base {
public:
private:
public:	
	Base();
	virtual void setup() = 0;
	virtual void draw() const = 0;
	virtual ~Base();
};

