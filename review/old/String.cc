#include "String.hh"
#include <memory.h>

String::String(const String& orig) :
	len(orig.len), capacity(orig.capacity),
	s(new char [capacity])
{
  memcpy(s, orig.s, len);
}

String& String::operator =(const String& orig) {
	String copy(orig); // made a copy
	len = copy.len;
	capacity = orig.capacity;
	swap(s, copy.s); // VERY IMPORTANT! this must be copy.s
	return *this;
}


