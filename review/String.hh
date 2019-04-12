#pragma once

#include <iostream>

class String {
private:
	uint32_t len;
	uint32_t capacity;
	char* s;
public:
  String() : len(0), capacity(0), s(nullptr) {}
	String(const char str[]);
	~String() { delete [] s; }
  String(const String& orig);
  String& operator =(const String& orig);
	String(String&& orig) : len(orig.len),
													capacity(orig.capacity),
													s(orig.s)
	{
		orig.s = nullptr;
	}

};


