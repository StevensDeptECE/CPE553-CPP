#include <iostream>
#include<string.h>
using namespace std;

class Elephant{ 
private:
	char* name;
public:
	Elephant(const char name[]) : name(new char[strlen(name)]) {
		strcpy(this->name, name);
	}
	~Elephant() { delete [] name; }
};

int main() {
	Elephant *e = new Elephant[10];
	Elephant *e2 = new Elephant[3]{"", "Alice", "Yu"};
}
