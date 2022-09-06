#pragma once
#include "Vehicle.hh"

class Truck : public Vehicle {
private:
	int numAxles;
	double weight;
public:
	Truck(int speed, int numAxles, double w)
		: Vehicle(speed), numAxles(numAxles), weight(w) {}
	double payToll() const {
		return numAxles* 15;
	}	
};
