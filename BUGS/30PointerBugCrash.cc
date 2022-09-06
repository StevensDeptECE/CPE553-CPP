#include <iostream>
#include <cstring>
using namespace std;

class Elephant {
private:
	const char* name;
public:
	Elephant(const char name[]) : name(name) {
	}
	~Elephant() { delete [] name; }
	friend ostream& operator <<(ostream& s, const Elephant& e) {
		return s << e.name << '\n';
	}
};

int main() {
	Elephant e("Fred");
	cout << e;
	Elephant e2("Jane");
	cout << e2;
}
