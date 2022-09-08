#include <iostream>
using namespace std;

/*
	forward references in simple classes are ok.
 */
class A {
public:
	A(int x, int y) : x(x), y(y) {}
	friend ostream& operator <<(ostream& s, A a) {
		return s << a.x << "," << a.y;
	}
private:
	int x,y;
};
