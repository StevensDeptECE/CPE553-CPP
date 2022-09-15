#include <iostream>
#include <cstring>
using namespace std;
class Person {
private:
	char firstName[10];
	char lastName[20];
	char building[15];
	int room;
public:
	Person(const char firstName[], const char lastName[], const char building[],
				 int room) :
		room(room)
	{
		strncpy(this->firstName, firstName, 10);
		strncpy(this->lastName, lastName, 20);
		strncpy(this->building, building, 15);
	}
	void print() const {
    cout << firstName << " " << lastName << " " << building << " " << room;
	}
};

int main() {
	const	Person p1("Dov", "Kruger", "Burchard", 217);
	const	Person p2("Vlad the Impaler", "Kruger", "Burchard", 217);
	p1.print();
	cout << '\n';
	//	p1.setName("Freddy");
	p1.print();
}
