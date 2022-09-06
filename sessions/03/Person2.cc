#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string firstName;
	string lastName;
	string building;
	int room;
public:
	Person(string firstName, string lastName, string  building, int room) :
		firstName(firstName), lastName(lastName), building(building),	room(room)
	{
	}
	void print() const {
    cout << firstName << " " << lastName << " " << building << " " << room;
	}
	void setFirstName(string name) {
		firstName = name;
	}
};

int main() {
	Person p1("Dov", "Kruger", "Burchard", 217);
	p1.print();
	cout << '\n';
	p1.setFirstName("Freddy");
	p1.print();
}
