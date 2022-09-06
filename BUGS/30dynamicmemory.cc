#include <iostream>
using namespace std;

class A {
private:
	int* p;
	int len;
public:
	A(int n) : p(new int[n]), len(n) {
		for (int i = 0; i < n; i++)
			p[i] = 0;
	}
	~A() { delete [] p; }
	friend ostream& operator <<(ostream& s, const A& a) {
		for (int i = 0; i < a.len; i++)
			s << a.p[i];
		return s << '\n';
	}
};

int main() {
	A a1(5);
	cout << a1;
	A a2(a1);
	cout << a2;
}
