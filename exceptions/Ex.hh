#pragma once

#include <iostream>

class Ex {
private:
	const char* filename;
	int linenum;
	const char* msg;
public:
	Ex(const char* filename, int linenum, const char* msg)
		: filename(filename), linenum(linenum), msg(msg) {
	}
	friend ostream& operator <<(ostream& s, const Ex& e) {
		return s << e.filename << ":" << e.linenum << "\t" << e.msg << '\n';
	}
};

#define Ex1(msg) Ex(__FILE__, __LINE__, msg)
