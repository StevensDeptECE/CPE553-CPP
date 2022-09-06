#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
	virtual void payToll() const = 0;
	virtual double price() const = 0;
	virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
	int* p;
public:
	Car() { p = new int[10]; }
	~Car() {
		cout << "destroying car\n";
		delete[] p;
	}
	void payToll() const { cout << "$15"; }
  double price() const { return 20000; }
};

class Bus : public Vehicle {
public:
	void payToll() const { cout << "$3"; }
  double price() const { return 250000; }
	~Bus() {
		cout << "destroying bus\n";
	}
};

/*
	VFT Car
	Car::payToll
	Car::price

	VFT Bus
	Bus::payToll
	Bus::price
 */
int main() {
	//	Vehicle v; // illegal
	Car c;
	c.payToll();
	Bus b;
	b.payToll();

	Vehicle *v;
	v = &c;
	v->payToll(); // goes to the object, extracts pointer to VFT
	// goes there, and pulls the first pointer to the function Car::payToll
	cout << v->price(); // goes to the object, extracts pointer to VFT,
	v = &b;
	v->payToll();

	vector<Vehicle*> vehicles;
	vehicles.push_back(new Car());
	vehicles.push_back(new Bus());
	vehicles.push_back(new Bus());
	vehicles.push_back(new Car());
	for (auto v : vehicles) {
		v->payToll();
	}
	for (auto v : vehicles)
		delete v;
}
