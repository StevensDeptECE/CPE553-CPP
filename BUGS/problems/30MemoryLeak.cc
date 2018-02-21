#include <iostream>
using namespace std;

class Elephant {
private:
	char* name;
public:
	Elephant(const char name[]) : name(strlen(name)) {
	}
	~Elephant() { delete [] n; }
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
