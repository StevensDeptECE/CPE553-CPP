#pragma once
#include <iostream>

class Ex {
private:
	const char* filename;
	int linenum;
public:
	Ex(const char* filename, int linenum) : filename(filename), linenum(linenum) {}
	friend std::ostream& operator<<(std::ostream& s, const Ex& e) {
		return s << e.filename << ": " << e.linenum;
	}
};
