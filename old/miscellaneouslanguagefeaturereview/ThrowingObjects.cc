#include <iostream>
using namespace std;
class Ex {
private:
	const char* file;
	const char* msg;
	uint32_t line;
public:
	Ex(const char* file, uint32_t line, const char msg[])
		: file(file), line(line), msg(msg) {}
	friend ostream& operator <<(ostream& s, const Ex& e) {
		return s << e.file << ": " << e.line << ' ' << e.msg;
	}
};

class Malaria : public Ex {

public:
	Malaria(const char* file, uint32_t line) :
	  Ex(file, line, "Malaria") {}
}
double g(double x, double y) {
  if (y == 0)
		throw Ex(__FILE__, __LINE__, "DivByZero");
	return x/y;
}
void f() {
	Matrix m2(3,4);
	cout << g(1,2) << '\n';
	cout << g(3,0) << '\n';
}


int main() {
	try {
		Matrix m(3,4);
		f();
	} catch (const Ex& e) {
		cerr << e << '\n';
	}
#if 0
	catch (const Malaria& m) {

	} catch (const Tuberculosis& t) {

	}
#endif
}
