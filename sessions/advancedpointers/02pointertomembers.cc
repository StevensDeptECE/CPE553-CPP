#include <iostream>
#include <string>

using namespace std;
// see template sorting for another example using this
class A {
public: // just making this public to illustrate the pointers easily
	int age;
	int weight;
	string name;
	string type;
public:
	A(int age, int weight, string name, string type) :
		age(age), weight(weight), name(name), type(type) {}
};

// &A::age   pointer to member of A relative to start of object +0 bytes
// &A::weight pointer to member of A relative to start of object +4 bytes
// &A::name  pointer to member of A relative to start of object +8 bytes

int main() {
	A a1(100, 88, "Lonesome George", "Tortoise");
	cout << a1.name << '\n';

	string A::*p = &A::name;
	cout << a1.*p << '\n'; // call using pointer to member
	p = &A::type;
	cout << a1.*p << '\n'; // "Tortoise" using pointer to member
}
