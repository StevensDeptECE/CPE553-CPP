#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car;

class Person {
private:
  vector<Car*> owned;
	string name;
public:
  Person(const string& name) : owned(), name(name) {}
  void buy(Car& c) { owned.push_back(&c); }
};

class Car {
private:
	string color;
  vector<Person*> ownedBy;
public:
  Car(const char* color) : color(color), ownedBy() {}
};

#if 0
class Person {
public:
	Person* brother;
	Person* sister;
	Person* mother;
	Person* father;
};
#endif

// objects may not contain themselves,
//they may contain pointers to themselves
class Zebra {
private:
  Zebra* mate;
}


int main() {
  Person p("Dov");
  Car c1("red");
  Car c2("blue");
  p.buy(c1);
  p.buy(c2);
  
  Person p2("Ellen");
  p2.buyCar(p);

}
