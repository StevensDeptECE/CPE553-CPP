#include <iostream>
#include <vector>
using namespace std;

class Car;

class Person {
private:
  vector<Car*> owned;
public:
  Person() {}
  void buy(Car& c) { owned.push_back(&c); }
};

class Car {
private:
  vector<Person*> ownedBy;
public:


};

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
