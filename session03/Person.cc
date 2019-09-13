#include <iostream>
#include <cstring>
class Person {
private:
	const char firstName[10];
	const char lastName[20];
	const char building[15];
	int room;
public:
	Person(const char firstName[], const char lastName[], const char building[],
				 int room) :
		firstName(strncpy(this->firstName, firstName, 10)),
		lastName(strncpy(this->lastName, lastName, 20)),
		building(strncpy(this->building, building, 15)),
		room(room)
	{
	}
	void print() const {
    cout << firstName << " " << lastName << " " << building << " " << room;
	}
};

int main() {
	const	Person p1("Dov", "Kruger", "Burchard", 217);
	p1.print();
	cout << '\n'
	p1.setName("Freddy");
	p1.print();
}
