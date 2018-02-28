#pragma once

#include "Vehicle.hh"

class Bus : public Vehicle {
private:
	int numPassengers;
public:
	Bus(int speed, int numPassengers)
		: Vehicle(speed), numPassengers(numPassengers) {}
	double payToll() const {
		return 4;
	}
};
