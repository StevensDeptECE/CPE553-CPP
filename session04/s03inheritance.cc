#include <iostream>
using namespace std;

class Vehicle { // class becomes abstract with pure virtual function
private:
	double speed;
public:
	Vehicle(double speed) : speed(speed) {}
	friend ostream& operator <<(ostream& s, const Vehicle& v) {
    return s << v.speed;
	}
	virtual	void payToll() const = 0; // a class that contains 1 or more pure virtual functions is abstract
};

// has speed and number of passengers
class Bus : public Vehicle { // A bus IS_A Vehicle  IS_A KIND OF
private:
	int numPassengers;
public:
	Bus(double speed, int numPassengers)
		: Vehicle(speed), numPassengers(numPassengers)  { // the order of initialization is the order in memory.  Specifying out of order is IGNORED
		//this->speed = speed; //not allowed
	}
  void payToll() const override {
		cout << "$4";
	}
};

// has a speed and weight and number of axles
class Truck : public Vehicle {
private:
	double weight;
	int numAxles;
public:
	Truck(double speed, double weight, int numAxles)
		: Vehicle(speed), weight(weight), numAxles(numAxles) {}
  void payToll() const override {
		cout << '$' << 20 * numAxles;
	}

};

// has color and speed
class Car : public Vehicle {
private:
	string color;
public:
	Car(double speed, const string& color)
		: Vehicle(speed), color(color) {}
	void payToll() const override {
		cout << "$15";
	}
};

int main() {
	//	const Vehicle v(45); // vehicle is abstract, cannot make one instantiate
	const Truck t(90.5, 12000, 5);  // speed, weight, #axles
	const Bus b(55.5, 13);			// speed, numberof passengers
	const Car c(55.5, "red");       // speed, color
	//Vehicle v(55);
	t.payToll();
	b.payToll();
	c.payToll();

	const Vehicle* v = &t;
	v->payToll(); // this looks at the pointer
	v = &b;
	v = &c;

cout << '\n';
//	The VFT lets you write:     VFT = virtual function table 🅱️
    const Vehicle* a[]{&t, &c, &b};
	for (auto v : a) {
		v->payToll(); // pay your toll, whatever you are (polymorphism)
	}
}
/*
v------> +--------+                  VFT for Truck
         |ptr ----+--------------->  Truck::payToll --------->    Truck::payToll() {}
         |Vehicle |
         |Truck   |

*/