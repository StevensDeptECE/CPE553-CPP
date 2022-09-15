#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
private:
	int speed;

public:
	Vehicle(int s) : speed(s) {}
	int getSpeed() const { return speed; }
	void printSpeed(ostream& s)const {
		s << speed;
	}
 	virtual void print(ostream& s) const = 0;
	friend ostream& operator <<(ostream& s, const Vehicle& v) {
    v.print(s);
		return s;
	}
};

class Car : public Vehicle {
private:
	string color;
public:
	Car(int speed, const string& color) : Vehicle(speed), color(color) {}
	void print(ostream& s) const override {
		Vehicle::printSpeed(s); s << " color=" << color;
	}
};

class Bus : public Vehicle {
private:
	int numPassengers;
public:
	Bus(int speed, int numPassengers) :
		Vehicle(speed), numPassengers(numPassengers) {}
	void print(ostream& s) const override {
		Vehicle::printSpeed(s); s << " passengers=" << numPassengers;
	}
};

class Truck : public Vehicle {
private:
	double w;
public:
	Truck(int speed, double grossWeight) : Vehicle(speed), w(grossWeight) {}
	void print(ostream& s) const override {
		Vehicle::printSpeed(s); s << " weight=" << w;
	}
};

class VehicleSim {
private:
	vector<Vehicle*> vehicles;
public:
	VehicleSim() : vehicles() {}
	~VehicleSim() {
		for (auto v : vehicles)
			delete v;
	}
	void add(Vehicle* v) {
    vehicles.push_back(v);
	}

	friend ostream& operator <<(ostream& s, const VehicleSim& sim) {
		for (auto v : sim.vehicles) {
			cout << *v;
		}
		return s;
	}
	
};

int main() {
	VehicleSim sim;
	Car c1(55, "red");
	//THIS WILL CRASH	sim.add(&c1); //55 mph, "Red"
	sim.add(new Car(55, "red")); //55 mph, "Red"
	sim.add(new Bus(40, 12)); // 40mph ,12 passengers
	sim.add(new Truck(90, 80000.0)); // 90mph, 40 tons
	cout << sim;
}
