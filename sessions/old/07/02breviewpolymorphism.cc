#include <iostream>
#include <string>
using namespace std;

class Vehicle { // BASE CLASS     o-o: Parent class, abstract class
private:
	int speed;
public:
	Vehicle(int s) : speed(s) {}
	virtual int payToll() = 0; // this class is ABSTRACT
};

class Car : public Vehicle { // DERIVED CLASS    o-o: child class
private:
	string color;
public:
	Car(int s, const string& color) : Vehicle(s), color(color) {}
	int payToll() {
		return 15;
	}

};

class Sportscar : public Car {
private:
	int hp;
public:
	Sportscar(int s, const string& color, int hp) : Car(s, color), hp(hp) {}
	int payToll() {
		return 25;
	}
};


class Bus : public Vehicle  {
private:
	int numPassengers;
public:
	Bus(int s, int n) : Vehicle(s), numPassengers(n) {}
  int payToll() {
		return 4;
	}
};

class Truck  : public Vehicle {
private:
	int axles;
	double weight;
public:
	Truck(int s, int axles, double w) : Vehicle(s), axles(axles), weight(w) {}
	int payToll() {
		return 20 * axles;
	}

};


int main() {
	Car c(55, "red");
	Bus b(40, 28);
	Truck t(77, 5, 18000);
	//	cout << c.payToll(); // $15
	//	cout << b.payToll(); // $4
	//	cout << t.payToll(); // $20 * axles

	string red = "red";
	Sportscar s(90, red, 450);
	Vehicle* vehicles[4];
	vehicles[0] = &c;
	vehicles[1] = &b;
	vehicles[2] = &t;
	vehicles[3] = &s;
	for (int i = 0; i < 4; i++)
		cout << vehicles[i]->payToll() << '\n'; //polymorphism
	
}
