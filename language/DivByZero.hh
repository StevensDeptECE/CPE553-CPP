#include "Exception.hh"

class DivByZero : public Ex {
public:
	DivByZero(const char* filename, int linenum) : Ex(filename, linenum) {}
};
