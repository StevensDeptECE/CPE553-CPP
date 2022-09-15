#include <iostream>
using namespace std;

class Ex {
private:
	const char* filename;
	int linenum;
	const char* msg;
public:
	Ex(const char *filename, int linenum, const char* msg) : filename(filename), linenum(linenum), msg(msg) {}
	friend ostream& operator <<(ostream& s, const Ex& e) {
		return s << e.filename << ": " << e.linenum << "\t" << e.msg << '\n';
	}
};

void f() {
	throw Ex(__FILE__, __LINE__, "HELP!");
}

int main() {
	try {
		f();
	} catch(const Ex& e) {
		cout << e << '\n';
	}
}
